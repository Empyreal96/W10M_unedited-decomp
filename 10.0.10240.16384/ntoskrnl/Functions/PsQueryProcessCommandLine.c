// PsQueryProcessCommandLine 
 
int __fastcall PsQueryProcessCommandLine(int a1, int a2, unsigned int a3, int a4, unsigned int *a5)
{
  int v6; // r10
  _DWORD *v7; // r0
  unsigned int v8; // lr
  unsigned int v9; // r6
  int v10; // r9
  int v11; // r5
  unsigned int v12; // r6
  unsigned int v13; // r4
  int v14; // r3
  _DWORD *v15; // r2
  unsigned int v16; // r3
  int v17; // r3
  unsigned int *v18; // r0
  unsigned int v19; // r4
  unsigned int v20; // r1
  int v23; // [sp+20h] [bp-58h]
  int v24; // [sp+24h] [bp-54h]
  unsigned int *v25; // [sp+2Ch] [bp-4Ch] BYREF
  unsigned int *v26; // [sp+30h] [bp-48h]
  unsigned int v27; // [sp+34h] [bp-44h]
  int v28; // [sp+38h] [bp-40h]
  int v29; // [sp+3Ch] [bp-3Ch]
  _DWORD _40[19]; // [sp+40h] [bp-38h] BYREF
  int varg_r3; // [sp+8Ch] [bp+14h]

  _40[16] = a1;
  _40[17] = a2;
  varg_r3 = a4;
  v23 = (char)a4;
  LOBYTE(varg_r3) = a4;
  v27 = a3;
  _40[18] = a3;
  v6 = a1;
  v28 = a1;
  v29 = a2;
  v26 = a5;
  v25 = a5;
  v7 = (_DWORD *)(a1 + 172);
  __pld(v7);
  v8 = *v7 & 0xFFFFFFFE;
  do
    v9 = __ldrex(v7);
  while ( v9 == v8 && __strex(v8 + 2, v7) );
  __dmb(0xBu);
  if ( v9 == v8 )
  {
    v10 = 1;
  }
  else
  {
    v10 = ExfAcquireRundownProtection(v7);
    if ( !v10 )
    {
      v11 = -1073741558;
      goto LABEL_30;
    }
  }
  v12 = 0;
  v13 = 0;
  v24 = 0;
  v11 = 0;
  KiStackAttachProcess(v6, 0, (int)_40);
  v14 = *(_DWORD *)(v6 + 320);
  if ( v14 )
  {
    v15 = (_DWORD *)(*(_DWORD *)(v14 + 16) + 64);
    if ( (unsigned int)v15 >= MmUserProbeAddress )
      v15 = (_DWORD *)MmUserProbeAddress;
    v24 = v15[1];
    v13 = (unsigned __int16)HIWORD(*v15);
    v12 = (unsigned __int16)*v15;
  }
  else
  {
    v11 = -1073741275;
  }
  KiUnstackDetachProcess((unsigned int)_40, 0);
  if ( v11 < 0 )
    goto LABEL_29;
  if ( !v12 || v12 > v13 || (v12 & 1) != 0 || (v13 & 1) != 0 || !v24 )
  {
    v11 = -1073741275;
LABEL_29:
    v6 = a1;
    goto LABEL_30;
  }
  v16 = v13 + 8;
  if ( v26 )
    *v26 = v16;
  if ( v27 >= v16 )
  {
    *(_WORD *)a2 = v12;
    *(_WORD *)(a2 + 2) = v13;
    if ( v13 )
      v17 = a2 + 8;
    else
      v17 = 0;
    *(_DWORD *)(a2 + 4) = v17;
    v6 = a1;
    v11 = MmCopyVirtualMemory(
            a1,
            v24,
            *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74),
            a2 + 8,
            v13,
            v23,
            &v25);
    if ( v11 >= 0 )
      v11 = 0;
  }
  else
  {
    v11 = -1073741820;
    v6 = a1;
  }
LABEL_30:
  if ( v10 )
  {
    v18 = (unsigned int *)(v6 + 172);
    __pld((void *)(v6 + 172));
    v19 = *(_DWORD *)(v6 + 172) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v20 = __ldrex(v18);
    while ( v20 == v19 && __strex(v19 - 2, v18) );
    if ( v20 != v19 )
      ExfReleaseRundownProtection((unsigned __int8 *)v18);
  }
  return v11;
}
