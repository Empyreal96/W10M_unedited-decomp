// KiConnectInterruptInternal 
 
int __fastcall KiConnectInterruptInternal(int a1, int a2)
{
  unsigned int v3; // r6
  int v4; // r10
  unsigned int v5; // r2
  unsigned int v6; // r4
  int v7; // r7
  int v9; // r8
  int v10; // r2
  unsigned int v11; // r1
  int *v12; // r4
  int v13; // r6
  int v14; // r0
  int result; // r0
  unsigned int v16; // r4
  _BYTE *v17; // r7
  _BYTE *v18; // r0
  unsigned int *v19; // r2
  unsigned int v20; // r4
  int v21; // r3
  int v22; // [sp+0h] [bp-40h] BYREF
  int v23; // [sp+4h] [bp-3Ch]
  int v24; // [sp+8h] [bp-38h]
  char v25[48]; // [sp+10h] [bp-30h] BYREF

  v3 = *(_DWORD *)(a1 + 44);
  v4 = 0;
  v5 = *(unsigned __int8 *)(a1 + 48);
  v6 = *(_DWORD *)(a1 + 52);
  v7 = 15;
  v9 = 0;
  if ( v3 > 0xFFF
    || v5 > 0xF
    || v6 >= KeNumberProcessors_0 && !a2
    || *(_BYTE *)(a1 + 49) && *(unsigned __int8 *)(a1 + 49) < v5 )
  {
    return -1073741585;
  }
  if ( a2 != 1 )
  {
    v10 = (int)*(&KiProcessorBlock + v6);
    v22 = 0;
    v23 = 0;
    v24 = 0;
    v23 = *(unsigned __int8 *)(v10 + 1052);
    v22 = *(_DWORD *)(v10 + 1048);
    KeSetSystemGroupAffinityThread(&v22, v25);
    if ( (v3 & 0xF0) != 0 )
    {
      v16 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      if ( !*(_DWORD *)(v16 + 1324) )
      {
        v17 = (_BYTE *)ExAllocatePoolWithTag(512, 4096, 538993995);
        v18 = memset(v17, 0, 4096);
        if ( v17 )
        {
          __dmb(0xBu);
          v19 = (unsigned int *)(v16 + 1324);
          do
            v20 = __ldrex(v19);
          while ( !v20 && __strex((unsigned int)v17, v19) );
          __dmb(0xBu);
          if ( v20 )
            return sub_51BBBC(v18);
        }
      }
    }
    v7 = KfRaiseIrql(15);
  }
  if ( !*(_BYTE *)(a1 + 51) )
  {
    v11 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    if ( (v3 & 0xF0) != 0 )
    {
      if ( v3 - 2048 >= 0x400 )
        goto LABEL_21;
      v21 = *(_DWORD *)(v11 + 1324);
      if ( !v21 )
        goto LABEL_21;
      v12 = (int *)(v21 + 4 * (v3 - 2048));
    }
    else
    {
      v12 = (int *)(v11 + 4 * ((v3 & 0xF | (v3 >> 4) & 0xF0) + 75));
    }
    if ( v12 )
    {
      v13 = *v12;
      if ( *v12 )
      {
        v4 = 1;
        if ( *(_DWORD *)(a1 + 64) != *(_DWORD *)(v13 + 64) )
          goto LABEL_21;
        if ( !*(_BYTE *)(a1 + 56) )
          goto LABEL_21;
        if ( !*(_BYTE *)(v13 + 56) )
          goto LABEL_21;
        v14 = *v12;
        *(_BYTE *)(a1 + 51) = 1;
        v9 = 1;
        KiInsertInterruptObjectOrdered(v14, a1);
        if ( *(_BYTE *)(v13 + 49) || !*(_BYTE *)(a1 + 49) )
          goto LABEL_21;
      }
      else
      {
        *(_BYTE *)(a1 + 51) = 1;
        v9 = 1;
      }
      *v12 = a1;
    }
  }
LABEL_21:
  if ( a2 != 1 )
    KiReleaseInterruptConnectLock(v7, v25);
  if ( !v9 )
    return -1073741585;
  if ( v4 )
    result = 295;
  else
    result = 0;
  return result;
}
