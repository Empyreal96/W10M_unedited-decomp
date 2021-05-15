// NtAlpcQueryInformationMessage 
 
int __fastcall NtAlpcQueryInformationMessage(int a1, int a2, int a3, int a4, int a5, unsigned int a6)
{
  unsigned int v6; // r5
  int v7; // r0
  int v8; // r9
  int v9; // r10
  unsigned int v10; // r6
  _DWORD *v11; // r2
  int v12; // r4
  int v13; // r5
  int v14; // r0
  int v15; // r9
  unsigned int *v16; // r8
  unsigned int v17; // r1
  unsigned int *v18; // r2
  unsigned int v19; // r0
  int v20; // r0
  unsigned int v21; // r1
  __int16 v22; // r3
  int v24; // [sp+Ch] [bp-34h] BYREF
  int v25; // [sp+10h] [bp-30h]
  _DWORD v26[3]; // [sp+14h] [bp-2Ch] BYREF
  int v27; // [sp+20h] [bp-20h]
  int varg_r0; // [sp+48h] [bp+8h]
  int varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  varg_r1 = a2;
  v25 = a4;
  varg_r3 = a4;
  v27 = a3;
  varg_r2 = a3;
  v26[0] = a1;
  varg_r0 = a1;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v24 = v7;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) && (a2 & 7) != 0 )
    ExRaiseDatatypeMisalignment(v7);
  v8 = *(_DWORD *)(a2 + 16);
  v26[2] = v8;
  v9 = *(_DWORD *)(a2 + 20);
  v26[1] = v9;
  if ( v7 )
  {
    v7 = ProbeForWrite(a4, a5, 4);
    v10 = a6;
    if ( a6 )
    {
      v11 = (_DWORD *)a6;
      if ( a6 >= MmUserProbeAddress )
        v11 = (_DWORD *)MmUserProbeAddress;
      *v11 = *v11;
    }
  }
  else
  {
    v10 = a6;
  }
  if ( v8 )
  {
    v7 = ObReferenceObjectByHandle(v26[0], 0x20000, AlpcPortObjectType, v24, &v24);
    v12 = v7;
    if ( v7 < 0 )
      goto LABEL_45;
    v12 = AlpcpLookupMessage(v24, v8, v9, v26);
    if ( v12 < 0 )
    {
LABEL_44:
      v7 = ObfDereferenceObject(v24);
      goto LABEL_45;
    }
    v13 = v26[0];
    if ( *(_DWORD *)(v26[0] + 12) )
    {
      if ( v27 )
      {
        if ( v27 != 1 )
        {
          if ( v27 != 2 || v25 || a5 || v10 )
          {
            v12 = -1073741811;
          }
          else
          {
            v12 = 0;
            if ( (*(_DWORD *)(v26[0] + 20) & 7) != 4 )
              v12 = 259;
          }
          goto LABEL_28;
        }
        v14 = AlpcpQueryTokenModifiedIdMessage(v24, v26[0], v25, a5, v10, 0);
      }
      else
      {
        v14 = AlpcpQuerySidMessage(v24, v26[0], v25, a5, v10, 0);
      }
      v12 = v14;
    }
    else
    {
      v12 = -1073740029;
    }
LABEL_28:
    if ( AlpcpMessageLogEnabled )
      AlpcpEnterStateChangeEventMessageLog(v13);
    v15 = 0;
    if ( (*(_BYTE *)(v13 - 16) & 1) != 0 )
    {
      v15 = 0x10000 - *(__int16 *)(v13 - 14);
      *(_BYTE *)(v13 - 16) &= 0xFEu;
      *(_WORD *)(v13 - 14) = 0;
    }
    v16 = (unsigned int *)(v13 - 4);
    __dmb(0xBu);
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 - 1, v16) );
    if ( (v17 & 2) != 0 && (v17 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v13 - 4));
    KeAbPostRelease(v13 - 4);
    if ( v15 > 0 )
    {
      __dmb(0xBu);
      v18 = (unsigned int *)(v13 - 12);
      do
      {
        v19 = __ldrex(v18);
        v20 = v19 - v15;
      }
      while ( __strex(v20, v18) );
      __dmb(0xBu);
      if ( v20 <= 0 )
      {
        if ( v20 )
          KeBugCheckEx(24, 0, v13, 40, v20);
        AlpcpDestroyBlob(v13);
      }
    }
    goto LABEL_44;
  }
  v12 = -1073741811;
LABEL_45:
  v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v22 = *(_WORD *)(v21 + 0x134) + 1;
  *(_WORD *)(v21 + 308) = v22;
  if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
    KiCheckForKernelApcDelivery(v7);
  return v12;
}
