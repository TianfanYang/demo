#include "catalog.h"
#include "query.h"

/*
 * Inserts a record into the specified relation.
 *
 * Returns:
 *     OK on success
 *     an error code otherwise
 */

const Status QU_Insert(const string & relation,
    const int attrCnt,
    const attrInfo attrList[])
{

AttrDesc *attrs;
Record record;
int allAttrCnt;
Status status;
RID outRid;
int length=0;
for(int i=0; k < attrCnt; i ++){
  if(attrList[i].attrValue == NULL){
       return ATTRTYPEMISMATCH;
        }
    }
InsertFileScan insertscan(relation, status);
if(status!=OK){
  return status;
}
for(int i=0;i<allAttrCnt;i++){
status = attrCat->getRelInfo(relation, allAttrCnt, attrs);
if(status!=OK){
  return status;
}
 length+=attrs[i].attrLen;
}
char x[length];
record.data = (void *)x;
record.length = length;

for (int i=0;i<attrCnt;i++){
   for (int j = 0; j < allAttrCnt; j++) {
       if (strcmp(attrs[j].attrName, attrList[i].attrName) == 0) {
  int int;
    float float;
     switch (attrList[i].attrType) {
      case INTEGER:
           int = atoi((char*) attrList[i].attrValue);
          memcpy(x + attrs[j].attrOffset, (char*)&int, attrs[j].attrLen);
               break;
      case FLOAT:
            float = atof((char*) attrList[i].attrValue);
           memcpy(x + attrs[j].attrOffset, (char*)&float, attrs[j].attrLen);
             break;
      case STRING:
           memcpy(x+ attrs[j].attrOffset, (char*)attrList[i].attrValue, attrs[j].attrLen);
           break;
     }
}
   }
}
status = insertscan.insertRecord(record, outRid);
if(status != OK){
  return status;
  }
return OK;
}
