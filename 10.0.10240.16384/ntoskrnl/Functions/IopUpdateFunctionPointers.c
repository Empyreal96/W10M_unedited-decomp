// IopUpdateFunctionPointers 
 
int (__fastcall **__fastcall IopUpdateFunctionPointers(int a1, int a2, int a3, int a4))(_DWORD, _DWORD)
{
  int v7; // r3
  unsigned int *v8; // r4
  unsigned int v9; // r1
  unsigned int v10; // r1
  int (__fastcall **result)(_DWORD, _DWORD); // r0
  unsigned int v12; // r1
  int (__fastcall *v13)(int, char, int); // r2
  unsigned int v14; // r1
  unsigned int v15; // r1
  bool v16; // zf
  unsigned int v17; // r1
  unsigned int v18; // r1
  unsigned int v19; // r2
  unsigned int v20; // r1
  unsigned int v21; // r1
  _DWORD v22[6]; // [sp+0h] [bp-18h] BYREF

  v22[0] = a2;
  v22[1] = a3;
  v22[2] = a4;
  if ( !a3 )
    KeAcquireInStackQueuedSpinLock((unsigned int *)&IopFunctionPointerLock, (unsigned int)v22);
  if ( a2 )
    v7 = IopFunctionPointerMask | a1;
  else
    v7 = IopFunctionPointerMask & ~a1;
  IopFunctionPointerMask = v7;
  __dmb(0xBu);
  v8 = (unsigned int *)&pIoFreeIrp;
  if ( (v7 & 1) != 0 )
  {
    do
      v9 = __ldrex((unsigned int *)&pIoAllocateIrp);
    while ( __strex((unsigned int)IovAllocateIrp, (unsigned int *)&pIoAllocateIrp) );
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)&pIofCallDriver);
    while ( __strex((unsigned int)IovCallDriver, (unsigned int *)&pIofCallDriver) );
    __dmb(0xBu);
    result = &pIofCompleteRequest;
    do
      v12 = __ldrex((unsigned int *)&pIofCompleteRequest);
    while ( __strex((unsigned int)IovCompleteRequest, (unsigned int *)&pIofCompleteRequest) );
    __dmb(0xBu);
    v13 = (int (__fastcall *)(int, char, int))IovFreeIrpPrivate;
  }
  else
  {
    do
      v15 = __ldrex((unsigned int *)&pIoFreeIrp);
    while ( __strex((unsigned int)IopFreeIrp, (unsigned int *)&pIoFreeIrp) );
    __dmb(0xBu);
    v16 = (IopFunctionPointerMask & 2) == 0;
    __dmb(0xBu);
    if ( v16 )
    {
      do
        v19 = __ldrex((unsigned int *)&pIofCallDriver);
      while ( __strex(0, (unsigned int *)&pIofCallDriver) );
      __dmb(0xBu);
      result = &pIofCompleteRequest;
      do
        v20 = __ldrex((unsigned int *)&pIofCompleteRequest);
      while ( __strex((unsigned int)IopfCompleteRequest, (unsigned int *)&pIofCompleteRequest) );
    }
    else
    {
      do
        v17 = __ldrex((unsigned int *)&pIofCallDriver);
      while ( __strex((unsigned int)IopPerfCallDriver, (unsigned int *)&pIofCallDriver) );
      __dmb(0xBu);
      result = &pIofCompleteRequest;
      do
        v18 = __ldrex((unsigned int *)&pIofCompleteRequest);
      while ( __strex((unsigned int)IopPerfCompleteRequest, (unsigned int *)&pIofCompleteRequest) );
    }
    __dmb(0xBu);
    v16 = (IopFunctionPointerMask & 4) == 0;
    __dmb(0xBu);
    if ( v16 )
    {
      do
        v21 = __ldrex((unsigned int *)&pIoAllocateIrp);
      while ( __strex((unsigned int)IopAllocateIrpPrivate, (unsigned int *)&pIoAllocateIrp) );
      goto LABEL_27;
    }
    v13 = IopAllocateIrpWithExtension;
    v8 = (unsigned int *)&pIoAllocateIrp;
  }
  do
    v14 = __ldrex(v8);
  while ( __strex((unsigned int)v13, v8) );
LABEL_27:
  __dmb(0xBu);
  if ( !a3 )
    result = (int (__fastcall **)(_DWORD, _DWORD))KeReleaseInStackQueuedSpinLock((int)v22);
  return result;
}
