// NtQueryTimer 
 
int __fastcall NtQueryTimer(int a1, int a2, unsigned int a3, int a4, unsigned int a5)
{
  int v6; // r5
  int v7; // r9
  _DWORD *v8; // r6
  _DWORD *v9; // r1
  int v10; // r1
  int v11; // r8
  int i; // r2
  int v13; // r0
  unsigned int v14; // r10
  __int64 v15; // r0
  int v16; // kr00_4
  int v18; // [sp+10h] [bp-28h] BYREF
  unsigned int v19; // [sp+14h] [bp-24h]
  int v20; // [sp+18h] [bp-20h]
  int varg_r0; // [sp+40h] [bp+8h]
  int varg_r1; // [sp+44h] [bp+Ch]
  unsigned int varg_r2; // [sp+48h] [bp+10h]
  int varg_r3; // [sp+4Ch] [bp+14h]

  varg_r1 = a2;
  varg_r3 = a4;
  varg_r2 = a3;
  varg_r0 = a1;
  if ( a2 )
    return -1073741821;
  if ( a4 != 16 )
    return -1073741820;
  v7 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v7 )
  {
    if ( (a3 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a3 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a3 = *(_BYTE *)a3;
    *(_BYTE *)(a3 + 12) = *(_BYTE *)(a3 + 12);
    v8 = (_DWORD *)a5;
    if ( a5 )
    {
      v9 = (_DWORD *)a5;
      if ( a5 >= MmUserProbeAddress )
        v9 = (_DWORD *)MmUserProbeAddress;
      *v9 = *v9;
    }
  }
  else
  {
    v8 = (_DWORD *)a5;
  }
  v6 = ObReferenceObjectByHandle(a1, 1, ExTimerObjectType, v7, (int)&v18, 0);
  v10 = v18;
  v20 = v6;
  if ( v6 >= 0 )
  {
    v11 = *(_DWORD *)(v18 + 4);
    for ( i = 0; ; ++i )
    {
      v13 = MEMORY[0xFFFF900C];
      v19 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v14 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v13 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
    v15 = KeQueryTimerDueTime(v10);
    v16 = v15 - v14;
    v19 = (v15 - __PAIR64__(v19, v14)) >> 32;
    ObfDereferenceObject(v18);
    if ( v7 )
    {
      *(_BYTE *)(a3 + 8) = v11;
      *(_DWORD *)a3 = v16;
      *(_DWORD *)(a3 + 4) = v19;
      if ( v8 )
        *v8 = 16;
    }
    else
    {
      *(_BYTE *)(a3 + 8) = v11;
      *(_DWORD *)a3 = v16;
      *(_DWORD *)(a3 + 4) = v19;
      if ( v8 )
        *v8 = 16;
    }
  }
  return v6;
}
