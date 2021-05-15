// NtCancelIoFileEx 
 
int __fastcall NtCancelIoFileEx(int a1, int a2, unsigned int a3, int a4)
{
  _DWORD *v4; // r8
  _DWORD *v6; // r4
  int v7; // r5
  int v8; // r6
  _DWORD *v9; // r3
  int v10; // r0
  int v11; // r4
  unsigned __int64 *v12; // r3
  unsigned __int64 v13; // kr00_8
  unsigned int *v14; // r2
  unsigned int v15; // r1
  int v16; // r0
  char v18; // [sp+8h] [bp-30h]
  int v19; // [sp+Ch] [bp-2Ch] BYREF
  _DWORD _10[16]; // [sp+10h] [bp-28h] BYREF

  _10[15] = a4;
  v4 = (_DWORD *)a3;
  _10[14] = a3;
  _10[13] = a2;
  _10[12] = a1;
  v18 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v18 )
  {
    v6 = (_DWORD *)a3;
    if ( a3 >= MmUserProbeAddress )
      v6 = (_DWORD *)MmUserProbeAddress;
    *v6 = *v6;
  }
  v7 = ObReferenceObjectByHandle(a1, 0, IoFileObjectType, v18, &v19);
  v8 = v19;
  if ( v7 >= 0 )
  {
    v9 = *(_DWORD **)(v19 + 124);
    if ( v9 )
    {
      if ( (*v9 & 4) != 0 )
      {
        v10 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        _10[0] = 0;
        v11 = PsReferencePrimaryToken(v10);
        SeQueryInformationToken(v11, 29, _10);
        ObfDereferenceObject(v11);
        if ( _10[0] )
        {
          ObfDereferenceObject(v8);
          v7 = -1073739504;
        }
      }
    }
    if ( v7 >= 0 )
    {
      if ( IoCountOperations == 1 )
      {
        v12 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 448);
        do
          v13 = __ldrexd(v12);
        while ( __strexd(v13 + 1, v12) );
        v14 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3036);
        do
          v15 = __ldrex(v14);
        while ( __strex(v15 + 1, v14) );
      }
      v16 = IopCancelIrpsInFileObjectList(v8, *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), a2, 0, 0, 0);
      if ( a2 && v16 || v16 | IopCancelIrpsInThreadListForCurrentProcess(v8, a2) )
        v7 = 0;
      else
        v7 = -1073741275;
      _10[0] = v7;
      *v4 = v7;
      v4[1] = 0;
      ObfDereferenceObject(v8);
    }
  }
  return v7;
}
