#ifndef SQLQUERY_H
#define SQLQUERY_H

#define qryCreateFileTable                                                     \
  "CREATE TABLE files (id INTEGER PRIMARY KEY, name TEXT, path TEXT, size "    \
  "UNSIGNED BIT INTEGER, toSave BOOLEAN, checksum UNSIGNED BIG INTEGER, "      \
  "UNIQUE(name, path) ON CONFLICT IGNORE)"
#define qryCreateIndexes                                                       \
  "CREATE INDEX index_size_checksum ON files (size, checksum)"
#define qryFilePath "select path, name from files where id == "
#define qrySelectDuplicates                                                    \
  "SELECT * FROM files WHERE checksum IN (SELECT checksum from files WHERE "   \
  "size IN (SELECT size from files  group by size having COUNT(size) > 1) "    \
  "group by checksum having COUNT(checksum) > 1) and  (name like "             \
  "':fileType') "                                                              \
  "order by size desc"
#define qryIDRandomDuplicatesFromPath                                          \
  "SELECT id, size FROM files WHERE checksum IN (SELECT checksum from files WHERE "  \
  "size IN (SELECT size from files  group by size having COUNT(size) > 1) "    \
  "group by checksum having COUNT(checksum) > 1)  "                            \
  "and (path ==':filePath') ORDER BY RANDOM() LIMIT 1"
#define qryIDRandomDuplicatesNotInPath "select id, size from files where checksum in (SELECT checksum FROM files WHERE checksum IN (SELECT checksum from files WHERE size IN (SELECT size from files  group by size having COUNT(size) > 1) group by checksum having COUNT(checksum) > 1) and (path == ':filePath')) AND (path != ':filePath') ORDER BY RANDOM() LIMIT 1"
#define qrySelectDuplicatesPaths                                               \
  "SELECT distinct path FROM files WHERE checksum IN (SELECT checksum from "   \
  "files WHERE "                                                               \
  "size IN (SELECT size from files  group by size having COUNT(size) > 1) "    \
  "group by checksum having COUNT(checksum) > 1) order by size desc"
#define qryUniqueChecksums                                                     \
  "select distinct checksum FROM files WHERE checksum IN (SELECT checksum "    \
  "from files WHERE  size IN (SELECT size from files  group by size having "   \
  "COUNT(size) > 1) group by checksum having COUNT(checksum) > 1)"
#define qryCountOfUniqueChecksums                                              \
  "select count(distinct checksum) as unique_count FROM files WHERE checksum " \
  "IN (SELECT checksum from files WHERE  size IN (SELECT size from files  "    \
  "group by size having COUNT(size) > 1) group by checksum having "            \
  "COUNT(checksum) > 1)"

#define qryCountOfUniqueChecksumsInPath                                        \
  "select count(distinct checksum) as unique_count FROM files WHERE checksum " \
  "IN (SELECT checksum from files WHERE  size IN (SELECT size from files  "    \
  "group by size having COUNT(size) > 1) group by checksum having "            \
  "COUNT(checksum) > 1) and (path ==':filePath') "

#define qryCountTotalFilesProcessed "select count(*) from files"
#define qryDeleteFileByID "DELETE from files where id == "
#define qryDeleteRandomDuplicate                                               \
  "DELETE from files where id == (select id FROM files WHERE checksum IN "     \
  "(SELECT checksum from files WHERE   size IN (SELECT size from files  "      \
  "group by size having COUNT(size) > 1)   group by checksum having "          \
  "COUNT(checksum) > 1) ORDER BY RANDOM() LIMIT 1)"
#define qryIDRandomDuplicate                                                   \
  "select id, size FROM files WHERE checksum IN "                                    \
  "(SELECT checksum from files WHERE   size IN (SELECT size from files  "      \
  "group by size having COUNT(size) > 1)   group by checksum having "          \
  "COUNT(checksum) > 1) ORDER BY RANDOM() LIMIT 1"
#endif // SQLQUERY_H
