// CmUnloadKeyEx 
 
int __fastcall CmUnloadKeyEx(int a1, int a2, unsigned int *a3, int a4)
{
  int v5; // r5
  unsigned int *v8; // r7
  unsigned int v9; // r4
  unsigned int v10; // r4
  int v12; // r2
  unsigned int v13; // r2
  unsigned int v14; // r2
  int v15; // r4
  unsigned int v16; // r2
  unsigned int v17; // r2
  int v18; // r3
  unsigned int v19; // r2
  unsigned int v20; // r2
  unsigned int *v21; // [sp+0h] [bp-20h] BYREF
  int v22; // [sp+4h] [bp-1Ch]

  v21 = a3;
  v22 = a4;
  v5 = *(_DWORD *)(a1 + 20);
  __dmb(0xBu);
  v8 = (unsigned int *)(v5 + 3324);
  do
  {
    v9 = __ldrex(v8);
    v10 = v9 + 1;
  }
  while ( __strex(v10, v8) );
  __dmb(0xBu);
  *(_DWORD *)(v5 + 4 * (((_BYTE)v10 - 1) & 0x7F) + 3328) = 10;
  if ( *(_BYTE *)(v5 + 2532) == 1 )
    return sub_7F0C14();
  LOBYTE(v21) = 0;
  v22 = -1;
  if ( !CmpTryToRundownHive(v5, (_DWORD *)a1, &v21) )
    goto LABEL_23;
  __dmb(0xBu);
  do
  {
    v16 = __ldrex(v8);
    v17 = v16 + 1;
  }
  while ( __strex(v17, v8) );
  __dmb(0xBu);
  v18 = v5 + 4 * (((_BYTE)v17 - 1) & 0x7F);
  *(_DWORD *)(v18 + 3328) = 12;
  v15 = CmUnloadKey(a1, 0, a3, v18);
  if ( v15 == -1073741535 )
  {
LABEL_23:
    if ( CmpReferenceKeyControlBlock((unsigned int *)a1) )
    {
      CmpSearchForOpenSubKeys(a1, 4, v12, 0);
      *(_WORD *)(a1 + 4) |= 0x20u;
      __dmb(0xBu);
      do
      {
        v13 = __ldrex(v8);
        v14 = v13 + 1;
      }
      while ( __strex(v14, v8) );
      __dmb(0xBu);
      *(_DWORD *)(v5 + 4 * (((_BYTE)v14 - 1) & 0x7F) + 3328) = 14;
      if ( a2 && (v15 = CmpRecordUnloadEventForHive(v5), v15 < 0) )
      {
        __dmb(0xBu);
        do
        {
          v19 = __ldrex(v8);
          v20 = v19 + 1;
        }
        while ( __strex(v20, v8) );
        __dmb(0xBu);
        *(_DWORD *)(v5 + 4 * (((_BYTE)v20 - 1) & 0x7F) + 3328) = 15;
        CmpDereferenceKeyControlBlock((unsigned int *)a1);
      }
      else
      {
        *(_BYTE *)(v5 + 2532) = 1;
        *(_DWORD *)(v5 + 2528) = a1;
        v15 = 259;
      }
    }
    else
    {
      v15 = -1073741670;
    }
  }
  return v15;
}
