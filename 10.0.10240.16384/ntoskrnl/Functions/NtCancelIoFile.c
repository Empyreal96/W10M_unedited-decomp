// NtCancelIoFile 
 
int __fastcall NtCancelIoFile(int a1, unsigned int a2)
{
  _DWORD *v2; // r8
  int v3; // r10
  _DWORD *v4; // r2
  int v5; // r5
  int v6; // r6
  _DWORD *v7; // r3
  int v8; // r0
  int v9; // r4
  unsigned __int64 *v10; // r3
  unsigned __int64 v11; // kr00_8
  unsigned int *v12; // r2
  unsigned int v13; // r1
  int v14; // r9
  _DWORD *v15; // r5
  _DWORD *i; // r4
  int v17; // r4
  int v18; // r0
  _DWORD *j; // r2
  char v21; // [sp+9h] [bp-3Fh]
  unsigned int v22; // [sp+Ch] [bp-3Ch]
  int v23; // [sp+10h] [bp-38h] BYREF
  unsigned int v24[2]; // [sp+18h] [bp-30h] BYREF
  _DWORD *v25; // [sp+20h] [bp-28h]
  int anonymous2; // [sp+50h] [bp+8h]
  unsigned int anonymous3; // [sp+54h] [bp+Ch]

  v2 = (_DWORD *)a2;
  v25 = (_DWORD *)a2;
  anonymous3 = a2;
  anonymous2 = a1;
  v3 = 0;
  v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v24[0] = v22;
  v21 = *(_BYTE *)(v22 + 0x15A);
  if ( v21 )
  {
    v4 = (_DWORD *)a2;
    if ( a2 >= MmUserProbeAddress )
      v4 = (_DWORD *)MmUserProbeAddress;
    *v4 = *v4;
  }
  v5 = ObReferenceObjectByHandle(a1, 0, IoFileObjectType, v21, &v23);
  v6 = v23;
  if ( v5 >= 0 )
  {
    v7 = *(_DWORD **)(v23 + 124);
    if ( v7 )
    {
      if ( (*v7 & 4) != 0 )
      {
        v8 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v24[0] = 0;
        v9 = PsReferencePrimaryToken(v8);
        SeQueryInformationToken(v9, 29, v24);
        ObfDereferenceObject(v9);
        if ( v24[0] )
        {
          ObfDereferenceObject(v6);
          v5 = -1073739504;
        }
      }
    }
    if ( v5 >= 0 )
    {
      if ( IoCountOperations == 1 )
      {
        v10 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 448);
        do
          v11 = __ldrexd(v10);
        while ( __strexd(v11 + 1, v10) );
        v12 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3036);
        do
          v13 = __ldrex(v12);
        while ( __strex(v13 + 1, v12) );
      }
      v14 = KfRaiseIrql(1);
      v15 = (_DWORD *)(v22 + 908);
      for ( i = *(_DWORD **)(v22 + 908); v15 != i; i = (_DWORD *)*i )
      {
        if ( i[21] == v6 )
        {
          v3 = 1;
          IoCancelIrp((int)(i - 4));
        }
      }
      KfLowerIrql(v14);
      if ( v3 )
      {
        v24[0] = -100000;
        v24[1] = -1;
        while ( 1 )
        {
          v17 = 0;
          v18 = KfRaiseIrql(1);
          for ( j = *(_DWORD **)(v22 + 908); v15 != j; j = (_DWORD *)*j )
          {
            if ( j[21] == v6 )
            {
              v17 = 1;
              break;
            }
          }
          KfLowerIrql(v18);
          if ( !v17 )
            break;
          KeDelayExecutionThread(0, 0, v24);
        }
        v2 = v25;
      }
      IopCancelIrpsInFileObjectList(
        v6,
        *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74),
        0,
        __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0,
        1,
        0);
      *v2 = 0;
      v2[1] = 0;
      ObfDereferenceObject(v6);
      v5 = 0;
    }
  }
  return v5;
}
