// FsRtlLogCcFlushError 
 
int __fastcall FsRtlLogCcFlushError(unsigned __int16 *a1, int a2, int a3, int a4, char a5)
{
  int v8; // r9
  int v9; // r0
  int v10; // r5
  int v11; // r3
  unsigned int *v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r3
  int v15; // r7
  int v16; // r0
  int v17; // r6
  unsigned int v18; // r2
  unsigned int v19; // r1
  int v20; // r7
  int v21; // r0
  int v22; // r4
  unsigned int v23; // r5
  char *v24; // r4
  char *v25; // r3
  unsigned __int16 *varg_r0; // [sp+28h] [bp+8h]
  int varg_r1; // [sp+2Ch] [bp+Ch]
  int varg_r3; // [sp+34h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  v8 = 0;
  if ( !MmIsWriteErrorFatal(1, (*(_DWORD *)(a2 + 32) & 0x10) != 0, a4) )
    return 0;
  if ( a4 > -1073741623 )
  {
    if ( a4 > -1073741252 )
    {
      if ( a4 == -1073741247 || a4 == -1073740964 )
        goto LABEL_31;
      if ( a4 > -1073740699 )
      {
        if ( a4 <= -1073740697 )
          goto LABEL_31;
        v11 = -1073740672;
        goto LABEL_29;
      }
    }
    else
    {
      if ( a4 == -1073741252 || a4 == -1073741620 || a4 == -1073741309 )
        goto LABEL_31;
      if ( a4 > -1073741301 )
      {
        if ( a4 <= -1073741299 )
          goto LABEL_31;
        v11 = -1073741258;
        goto LABEL_29;
      }
    }
LABEL_30:
    v9 = -1073741278;
    v10 = -2147221454;
    goto LABEL_32;
  }
  if ( a4 == -1073741623 )
    goto LABEL_31;
  if ( a4 <= -1073741667 )
  {
    switch ( a4 )
    {
      case -1073741667:
LABEL_11:
        v9 = -1073700734;
        v10 = -2147221363;
        goto LABEL_32;
      case -1073741816:
      case -1073741790:
      case -1073741697:
        v9 = -1073700735;
        v10 = -2147221364;
        goto LABEL_32;
      case -1073741672:
        goto LABEL_11;
    }
    goto LABEL_30;
  }
  if ( a4 == -1073741662 )
    goto LABEL_11;
  if ( a4 == -1073741636 || a4 == -1073741634 )
    goto LABEL_31;
  v11 = -1073741628;
LABEL_29:
  if ( a4 != v11 )
    goto LABEL_30;
LABEL_31:
  v9 = -1073700736;
  v10 = -2147221365;
LABEL_32:
  v12 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4284);
  do
    v13 = __ldrex(v12);
  while ( __strex(v13 + 1, v12) );
  if ( (a5 & 1) == 0 )
    IoRaiseInformationalHardError(v9, a1, 0);
  if ( (a5 & 2) == 0 )
  {
    v14 = *a1 + 50;
    v15 = (unsigned __int8)v14;
    if ( v14 > 0x98 )
      v15 = 152;
    v16 = IoAllocateErrorLogEntry((__int16 *)a2, v15);
    v17 = v16;
    if ( v16 )
    {
      *(_BYTE *)v16 = 4;
      *(_WORD *)(v16 + 2) = 4;
      *(_DWORD *)(v16 + 12) = v10;
      *(_DWORD *)(v16 + 20) = a4;
      *(_DWORD *)(v16 + 40) = a4;
      *(_WORD *)(v16 + 4) = 1;
      *(_WORD *)(v16 + 6) = 48;
      v18 = *a1;
      v19 = v15 - 50;
      v20 = v16 + 48;
      v21 = v16 + 48;
      if ( v19 >= v18 )
      {
        memmove(v21, *((_DWORD *)a1 + 1), v18);
        v25 = (char *)(v20 + 2 * (*a1 >> 1));
      }
      else
      {
        v22 = (v19 >> 2) - 2;
        v23 = v19 - 2 * v22 - 8;
        memmove(v21, *((_DWORD *)a1 + 1), 2 * v22);
        v24 = (char *)(v20 + 2 * v22);
        qmemcpy(v24, " .. ", 8);
        v24 += 8;
        memmove((int)v24, *a1 - v23 + *((_DWORD *)a1 + 1), v23);
        v25 = &v24[v23];
      }
      *(_WORD *)v25 = 0;
      IoWriteErrorLogEntry(v17);
    }
    else
    {
      v8 = -1073741670;
    }
  }
  return v8;
}
