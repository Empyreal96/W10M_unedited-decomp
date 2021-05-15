// PsInsertSiloObject 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PsInsertSiloObject(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v7; // r5
  char v8; // r3
  int v9; // r0
  _DWORD *v10; // r6
  int v11; // r2
  int v12; // r3
  _DWORD *v13; // r1
  _DWORD *v14; // r2
  _DWORD *v15; // r1
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  int v20[6]; // [sp+8h] [bp-18h] BYREF

  v20[0] = a4;
  v4 = 0;
  if ( a1 == -1 )
  {
    v7 = PsGetCurrentSilo();
    if ( !v7 )
      return -1073741816;
  }
  else
  {
    v8 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v4 = ObReferenceObjectByHandle(a1, 2, PsSiloType, v8, (int)v20, 0);
    v7 = v20[0];
    if ( v4 < 0 )
      return v4;
  }
  v9 = ExAllocatePoolWithTag(1, 16, 1869375827);
  v10 = (_DWORD *)v9;
  if ( v9 )
  {
    *(_QWORD *)(v9 + 8) = *(_QWORD *)&a2;
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v12 = *(__int16 *)(v11 + 0x136) - 1;
    *(_WORD *)(v11 + 310) = v12;
    ExAcquireResourceExclusiveLite(v7 + 28, 1, v11, v12);
    v13 = *(_DWORD **)(v7 + 120);
    v14 = (_DWORD *)(v7 + 120);
    while ( v13 != v14 )
    {
      if ( a2 == v13[2] )
      {
        v4 = -1073741771;
        break;
      }
      v13 = (_DWORD *)*v13;
    }
    if ( v4 < 0 )
    {
      ExFreePoolWithTag((unsigned int)v10);
    }
    else
    {
      v15 = *(_DWORD **)(v7 + 124);
      *v10 = v14;
      v10[1] = v15;
      if ( (_DWORD *)*v15 != v14 )
        __fastfail(3u);
      *v15 = v10;
      *(_DWORD *)(v7 + 124) = v10;
    }
    v16 = ExReleaseResourceLite(v7 + 28);
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v18 = *(_WORD *)(v17 + 0x136) + 1;
    *(_WORD *)(v17 + 310) = v18;
    if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 )
      KiCheckForKernelApcDelivery(v16);
    PspDereferenceSiloObject(v7);
  }
  else
  {
    if ( v7 )
      PspDereferenceSiloObject(v7);
    v4 = -1073741670;
  }
  return v4;
}
