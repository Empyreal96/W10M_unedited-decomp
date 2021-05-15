// IopShutdownBaseFileSystems 
 
int __fastcall IopShutdownBaseFileSystems(int a1)
{
  int result; // r0
  __int64 v2; // r4
  __int64 v3; // r2
  _DWORD *v4; // r6
  int v5; // r3
  int v6; // r4
  int v7; // r0
  __int64 v8; // r2
  int v9; // [sp+Ch] [bp-2Ch]
  char v10[8]; // [sp+10h] [bp-28h] BYREF
  char v11[32]; // [sp+18h] [bp-20h] BYREF

  HIDWORD(v2) = a1;
  result = KeInitializeEvent((int)v11, 0, 0);
  LODWORD(v2) = *(_DWORD *)HIDWORD(v2);
  v3 = *(_QWORD *)*(_DWORD *)HIDWORD(v2);
  if ( __PAIR64__(HIDWORD(v3), *(_DWORD *)(v3 + 4)) != v2 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v2) = v3;
  for ( *(_DWORD *)(v3 + 4) = HIDWORD(v2); (_DWORD)v2 != HIDWORD(v2); result = ObfDereferenceObject((int)v4) )
  {
    v4 = (_DWORD *)(v2 - 52);
    *(_DWORD *)v2 = 0;
    *(_DWORD *)(v2 + 4) = 0;
    ObfReferenceObject(v2 - 52);
    IopIncrementDeviceObjectRefCount(v2 - 52, 1);
    v5 = *(_DWORD *)(v2 - 36);
    v6 = v2 - 52;
    if ( v5 )
      v6 = IoGetAttachedDevice((int)v4);
    v7 = ((int (__fastcall *)(int, int, _DWORD, _DWORD, _DWORD, char *, char *, int))IoBuildSynchronousFsdRequest)(
           16,
           v6,
           0,
           0,
           0,
           v11,
           v10,
           v9);
    if ( v7 && IofCallDriver(v6, v7) == 259 )
      KeWaitForSingleObject((unsigned int)v11, 0, 0, 0, 0);
    LODWORD(v2) = *(_DWORD *)HIDWORD(v2);
    v8 = *(_QWORD *)*(_DWORD *)HIDWORD(v2);
    if ( __PAIR64__(HIDWORD(v8), *(_DWORD *)(v8 + 4)) != v2 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v2) = v8;
    *(_DWORD *)(v8 + 4) = HIDWORD(v2);
    KeResetEvent((int)v11);
    IopDecrementDeviceObjectRef(v4, 0, 1);
  }
  return result;
}
