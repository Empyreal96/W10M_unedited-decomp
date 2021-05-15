// CcInitializeVacbs 
 
int **CcInitializeVacbs()
{
  _DWORD *v0; // r0
  int v1; // r0
  _DWORD *v2; // r4

  CcDbgNumberOfFailedMappingsDueToVacbSpace = 0;
  CcDbgNumberOfFailedHighPriorityMappingsDueToMmResources = 0;
  CcDbgNumberOfFailedHighPriorityMappingsDueToCcResources = 0;
  CcDbgNumberOfFailedHighPriorityMappings = 0;
  v0 = (_DWORD *)ExAllocatePoolWithTag(512, 4, 1633051459);
  CcVacbArrays = (int)v0;
  if ( !v0 )
    sub_970258();
  *v0 = 0;
  CcVacbFreeList = (int)&CcVacbFreeList;
  dword_632594 = (int)&CcVacbFreeList;
  CcVacbFreeHighPriorityList = (int)&CcVacbFreeHighPriorityList;
  dword_63259C = (int)&CcVacbFreeHighPriorityList;
  CcMinimumFreeHighPriorityVacbs = 64;
  v1 = CcAllocateInitializeVacbArray();
  v2 = (_DWORD *)v1;
  if ( !v1 )
    KeBugCheckEx(52, 590897, -1073741670, 0, 0);
  *(_DWORD *)(v1 + 4) = 1;
  CcBuildUpHighPriorityMappings(v1);
  return CcInsertVacbArray(v2);
}
