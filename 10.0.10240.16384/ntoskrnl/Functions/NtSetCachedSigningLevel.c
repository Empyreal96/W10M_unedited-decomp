// NtSetCachedSigningLevel 
 
int __fastcall NtSetCachedSigningLevel(int a1, int a2, unsigned int a3, unsigned int a4, int a5)
{
  unsigned int v5; // r9
  char v7; // r5
  _DWORD *v8; // r8
  unsigned int v9; // r6
  int v10; // r4
  int v11; // r3
  char v12; // r2
  char v13; // r1
  int v14; // r4
  int v15; // r0
  int v16; // r2
  int v18; // [sp+14h] [bp-2Ch]
  int varg_r0a; // [sp+48h] [bp+8h]
  int varg_r1; // [sp+4Ch] [bp+Ch]
  unsigned int varg_r2; // [sp+50h] [bp+10h]

  varg_r1 = a2;
  varg_r2 = a3;
  v5 = a4;
  LOBYTE(varg_r1) = a2;
  v7 = a1;
  v8 = 0;
  v9 = 0;
  if ( !dword_61D884 )
  {
    v10 = -1073741823;
    goto LABEL_38;
  }
  if ( (a2 & 0x30) != 0 )
    goto LABEL_4;
  if ( !a4 || a4 > 0x1000 )
    goto LABEL_37;
  if ( (a1 & 6) == 0 && a2 )
  {
LABEL_4:
    v10 = -1073741584;
    goto LABEL_38;
  }
  if ( (a1 & 3) == 3 )
    goto LABEL_10;
  v18 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v18 == 1 )
  {
    if ( (a1 & 2) == 0 )
    {
      v7 = a1 | 1;
      varg_r0a = a1 | 1;
      if ( ((a1 | 1) & 4) == 0 )
      {
        v11 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v12 = *(_BYTE *)(v11 + 733);
        v13 = *(_BYTE *)(v11 + 732);
        if ( (*(_BYTE *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 734) & 7) != 1 )
        {
          v10 = -1073741790;
          goto LABEL_38;
        }
        v9 = v13 & 0xF;
        if ( v9 >= (v12 & 0xFu) )
          v9 = v12 & 0xF;
      }
      goto LABEL_22;
    }
LABEL_10:
    v10 = -1073741585;
    goto LABEL_38;
  }
  if ( (a1 & 1) != 0 )
  {
    v9 = 15;
  }
  else
  {
    if ( (a1 & 2) == 0 )
      goto LABEL_10;
    v9 = 8;
  }
LABEL_22:
  v14 = 4 * v5;
  v15 = ExAllocatePoolWithTag(1, 4 * v5, 1668499779);
  v8 = (_DWORD *)v15;
  if ( !v15 )
  {
    v10 = -1073741670;
    goto LABEL_38;
  }
  if ( v18 == 1 && v14 )
  {
    if ( (a3 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v15);
    if ( v14 + a3 > MmUserProbeAddress || v14 + a3 < a3 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  memmove(v15, a3, 4 * v5);
  if ( (v7 & 6) == 0 )
  {
    v16 = a5;
LABEL_36:
    v10 = dword_61D884(v7 & 7, v18, a2, v9, v8, v5, v16);
    goto LABEL_38;
  }
  if ( v5 == 1 )
  {
    v16 = a5;
    if ( a5 != *v8 )
    {
      v10 = -1073741581;
      goto LABEL_38;
    }
    goto LABEL_36;
  }
LABEL_37:
  v10 = -1073741582;
LABEL_38:
  if ( v8 )
    ExFreePoolWithTag((unsigned int)v8);
  return v10;
}
