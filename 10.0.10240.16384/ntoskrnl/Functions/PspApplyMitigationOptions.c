// PspApplyMitigationOptions 
 
int __fastcall PspApplyMitigationOptions(int a1, int a2, _QWORD *a3, unsigned int a4)
{
  _QWORD *v4; // r4
  __int64 v5; // r6
  int result; // r0
  char v9; // r3
  unsigned int *v10; // r2
  unsigned int *v11; // r2
  unsigned int v12; // r2
  unsigned int *v13; // r2
  unsigned int *v14; // r2
  int v15; // r3
  unsigned int v16; // r4
  unsigned int v17; // r1
  unsigned int *v18; // r2
  unsigned int *v19; // r2
  unsigned int v20; // r0
  unsigned int *v21; // r2
  unsigned int *v22; // r2
  unsigned int *v23; // r2
  unsigned int v24; // r0
  unsigned int *v25; // r2
  unsigned int *v26; // r2
  int varg_r0; // [sp+28h] [bp+8h]
  int varg_r1; // [sp+2Ch] [bp+Ch]
  _QWORD *varg_r2; // [sp+30h] [bp+10h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v4 = a3;
  v5 = *a3;
  result = *(_DWORD *)a3 & 3;
  if ( result != 1 )
    return sub_7F6560();
  v9 = 13;
  if ( (v5 & 0x30) == 16 )
  {
    v9 = 13;
  }
  else if ( (v5 & 0x30) == 32 )
  {
    v9 = 77;
  }
  __dmb(0xBu);
  *(_BYTE *)(a1 + 107) = v9;
  if ( (v5 & 0x300) != 256 )
  {
    if ( (v5 & 0x300) != 768 )
      goto LABEL_9;
    __dmb(0xBu);
    v19 = (unsigned int *)(a1 + 188);
    do
      v20 = __ldrex(v19);
    while ( __strex(v20 | 0x1000000, v19) );
    __dmb(0xBu);
  }
  __dmb(0xBu);
  v10 = (unsigned int *)(a1 + 188);
  do
    result = __ldrex(v10);
  while ( __strex(result | 0x8000000, v10) );
  __dmb(0xBu);
LABEL_9:
  if ( (v5 & 0x30000) != 0 )
  {
    if ( (v5 & 0x30000) != 0x20000 )
    {
LABEL_14:
      v12 = a4;
      goto LABEL_15;
    }
    __dmb(0xBu);
    v11 = (unsigned int *)(a1 + 188);
    do
      result = __ldrex(v11);
    while ( __strex(result | 0x20000, v11) );
LABEL_13:
    __dmb(0xBu);
    goto LABEL_14;
  }
  v12 = a4;
  if ( (a4 & 1) == 0 )
  {
    __dmb(0xBu);
    v21 = (unsigned int *)(a1 + 188);
    do
      result = __ldrex(v21);
    while ( __strex(result | 0x20000, v21) );
    goto LABEL_13;
  }
LABEL_15:
  if ( (*(_DWORD *)(a1 + 188) & 0x20000) != 0 )
    goto LABEL_21;
  if ( (v5 & 0x300000) != 0 )
  {
    if ( (v5 & 0x300000) != 0x100000 )
      goto LABEL_21;
  }
  else if ( (v12 & 2) == 0 )
  {
    goto LABEL_21;
  }
  __dmb(0xBu);
  v13 = (unsigned int *)(a1 + 188);
  do
    result = __ldrex(v13);
  while ( __strex(result | 0x2000000, v13) );
  __dmb(0xBu);
  v12 = a4;
LABEL_21:
  if ( !a2 )
    goto LABEL_26;
  if ( (v5 & 0x3000000) == 0 )
  {
    if ( (v12 & 4) == 0 )
      goto LABEL_24;
LABEL_41:
    result = ObReferenceProcessHandleTable(a1);
    if ( result )
    {
      ExEnableHandleExceptions(result, 1);
      result = a1 + 172;
      __pld((void *)(a1 + 172));
      v16 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v17 = __ldrex((unsigned int *)result);
      while ( v17 == v16 && __strex(v16 - 2, (unsigned int *)result) );
      if ( v17 != v16 )
        result = (int)ExfReleaseRundownProtection((unsigned __int8 *)result);
    }
    v12 = a4;
    goto LABEL_24;
  }
  if ( (v5 & 0x3000000) == 0x1000000 )
    goto LABEL_41;
LABEL_24:
  v4 = a3;
  if ( *(int *)(a2 + 188) < 0 )
    LODWORD(v5) = v5 & 0xCFFFFFFF | 0x10000000;
LABEL_26:
  if ( (v5 & 0x30000000) == 0x10000000 )
  {
    __dmb(0xBu);
    v14 = (unsigned int *)(a1 + 188);
    do
      result = __ldrex(v14);
    while ( __strex(result | 0x80000000, v14) );
    __dmb(0xBu);
    v12 = a4;
  }
  if ( (BYTE4(v5) & 0x30) == 16 )
  {
    __dmb(0xBu);
    v22 = (unsigned int *)(a1 + 188);
    do
      result = __ldrex(v22);
    while ( __strex(result | 0x400, v22) );
    __dmb(0xBu);
    v12 = a4;
  }
  if ( (BYTE4(v5) & 3) == 1 )
  {
    __dmb(0xBu);
    v18 = (unsigned int *)(a1 + 188);
    do
      result = __ldrex(v18);
    while ( __strex(result | 0x4000000, v18) );
    __dmb(0xBu);
    v12 = a4;
  }
  if ( (v5 & 0x30000000000i64) != 0 )
  {
    if ( (WORD2(v5) & 0x300) != 256 )
      goto LABEL_34;
  }
  else if ( (v12 & 8) == 0 )
  {
    goto LABEL_34;
  }
  if ( dword_68124C )
  {
    __dmb(0xBu);
    v23 = (unsigned int *)(a1 + 192);
    do
      v24 = __ldrex(v23);
    while ( __strex(v24 | 0x10, v23) );
    __dmb(0xBu);
    result = KeSetCheckStackExtentsProcess(a1, 1);
    v12 = a4;
  }
LABEL_34:
  if ( (WORD2(v5) & 0x3000) == 4096 )
  {
    if ( *(unsigned __int8 *)(a1 + 732) < 8u )
      *(_BYTE *)(a1 + 732) = 8;
    if ( *(unsigned __int8 *)(a1 + 733) < 8u )
      *(_BYTE *)(a1 + 733) = 8;
  }
  if ( (v5 & 0x30) == 0 && (*(_DWORD *)(a1 + 192) & 0x10) != 0 )
    LODWORD(v5) = v5 & 0xFFFFFFCF | 0x10;
  v15 = HIWORD(v12) & 3;
  if ( v15 == 1 )
  {
    HIDWORD(v5) = HIDWORD(v5) & 0xFFFCFFFF | 0x10000;
  }
  else if ( v15 == 3 && (HIDWORD(v5) & 0x30000) != 0x10000 )
  {
    HIDWORD(v5) |= 0x30000u;
  }
  if ( (HIDWORD(v5) & 0x30000) == 0x10000 )
  {
    __dmb(0xBu);
    v25 = (unsigned int *)(a1 + 736);
    do
      result = __ldrex(v25);
    while ( __strex(result | 4, v25) );
    goto LABEL_87;
  }
  if ( (HIDWORD(v5) & 0x30000) == 196608 )
  {
    __dmb(0xBu);
    v26 = (unsigned int *)(a1 + 736);
    do
      result = __ldrex(v26);
    while ( __strex(result | 8, v26) );
LABEL_87:
    __dmb(0xBu);
  }
  *v4 = v5;
  return result;
}
