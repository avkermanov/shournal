#include "fileinfos.h"

#include "util.h"
#include "db_conversions.h"


void FileWriteInfo::write(QJsonObject &json) const
{
    json["path"] = path + QDir::separator() + name;
    json["size"] = size;
    json["mtime"] = QJsonValue::fromVariant(mtime);
    json["hash"] = QJsonValue::fromVariant(QVariant::fromValue(hash));
}

bool
FileWriteInfo::operator==(const FileWriteInfo &rhs) const
{
    return mtime == rhs.mtime &&
            size == rhs.size &&
            path == rhs.path &&
            name == rhs.name &&
            hash == rhs.hash;
}

////////////////////////////////////////////////////////////

void FileReadInfo::write(QJsonObject &json) const
{
    json["id"] = idInDb;
    json["path"] = path + QDir::separator() + name;
    json["size"] = size;
    json["mtime"] = QJsonValue::fromVariant(mtime);
    json["hash"] = QJsonValue::fromVariant(QVariant::fromValue(hash));
    json["isStoredToDisk"] = isStoredToDisk;
}

bool
FileReadInfo::operator==(const FileReadInfo &rhs) const
{
    if(idInDb != db::INVALID_INT_ID && rhs.idInDb != db::INVALID_INT_ID){
        return idInDb == rhs.idInDb;
    }

    return mtime == rhs.mtime &&
            size == rhs.size &&
            path == rhs.path &&
            name == rhs.name &&
            mode == rhs.mode &&
            hash == rhs.hash;
}
