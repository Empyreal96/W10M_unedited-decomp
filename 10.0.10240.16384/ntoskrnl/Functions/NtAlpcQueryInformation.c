// NtAlpcQueryInformation 
 
int __fastcall NtAlpcQueryInformation(int a1, int a2, unsigned int a3, int a4, unsigned int a5)
{
  unsigned int v6; // r6
  unsigned int v8; // r5
  int v9; // r5
  int v10; // lr
  unsigned int v11; // r1
  unsigned int v12; // r2
  unsigned int v13; // r2
  unsigned int v14; // r9
  _DWORD *v15; // r2
  int v16; // r4
  unsigned int v17; // r1
  __int16 v18; // r3
  _DWORD _10[14]; // [sp+10h] [bp-20h] BYREF

  _10[13] = a4;
  v6 = a3;
  _10[12] = a3;
  _10[11] = a2;
  _10[0] = a1;
  _10[10] = a1;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  if ( !a3 )
  {
    v9 = -1073741811;
    goto LABEL_37;
  }
  v10 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v10 )
  {
    if ( a2 != 3 && a2 != 11 && a4 )
    {
      v11 = a3;
      if ( (a3 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      v12 = a3 + a4 - 1;
      if ( v6 > v12 || v12 >= MmUserProbeAddress )
        ExRaiseAccessViolation();
      v13 = (v12 & 0xFFFFF000) + 4096;
      do
      {
        *(_BYTE *)v11 = *(_BYTE *)v11;
        v11 = (v11 & 0xFFFFF000) + 4096;
      }
      while ( v11 != v13 );
      a1 = _10[0];
    }
    v14 = a5;
    if ( a5 )
    {
      v15 = (_DWORD *)a5;
      if ( a5 >= MmUserProbeAddress )
        v15 = (_DWORD *)MmUserProbeAddress;
      *v15 = *v15;
    }
  }
  else
  {
    v14 = a5;
  }
  if ( a1 )
  {
    a1 = ObReferenceObjectByHandle(a1, 0x20000, AlpcPortObjectType, v10, (int)_10, 0);
    v9 = a1;
    v16 = _10[0];
    if ( a1 < 0 )
      goto LABEL_37;
  }
  else
  {
    v16 = 0;
  }
  if ( a2 )
  {
    switch ( a2 )
    {
      case 3:
        a1 = AlpcpPortQueryConnectedSidInfo(v16, v6);
        break;
      case 4:
        a1 = AlpcpPortQueryServerInfo(v16, v6, a4, v14, v10);
        break;
      case 11:
        a1 = AlpcpWaitForPortReferences(v16, v6, a4, v14, v10);
        break;
      default:
        v9 = -1073741811;
        goto LABEL_35;
    }
  }
  else
  {
    a1 = AlpcpPortQueryBasicInfo(v16, v6, a4, v14);
  }
  v9 = a1;
LABEL_35:
  if ( v16 )
    a1 = ObfDereferenceObject(v16);
LABEL_37:
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(a1);
  return v9;
}
