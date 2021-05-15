// CmpInitSIDToHiveMapping 
 
int CmpInitSIDToHiveMapping()
{
  return KeInitializeGuardedMutex((int)&CmpSIDMappingLock);
}
