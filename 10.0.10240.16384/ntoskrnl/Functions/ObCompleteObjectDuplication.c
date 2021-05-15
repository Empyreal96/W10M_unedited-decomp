// ObCompleteObjectDuplication 
 
int __fastcall ObCompleteObjectDuplication(_DWORD *a1, int a2, char a3, int *a4, _DWORD *a5)
{
  int v6; // r5
  int v8; // r0
  int v9; // r4
  BOOL v11; // r10
  int v12; // r6
  int v13; // r0
  int v14; // r5
  int v15; // r2
  int v16; // r9
  unsigned int *v17; // r0
  unsigned int v18; // r5
  unsigned int v19; // r4
  unsigned int *v20; // r0
  unsigned int v21; // r4
  unsigned int v22; // r1
  int v23; // r0
  int v24; // [sp+0h] [bp-48h]
  int v25; // [sp+10h] [bp-38h] BYREF
  int v26; // [sp+14h] [bp-34h]
  int *v27; // [sp+18h] [bp-30h]
  int v28; // [sp+1Ch] [bp-2Ch]
  int v29[10]; // [sp+20h] [bp-28h] BYREF

  *a4 = 0;
  v27 = a4;
  v6 = a3;
  v8 = ObReferenceProcessHandleTable(a2);
  v9 = v8;
  if ( !v8 )
    return sub_7F6870();
  v11 = v8 == ObpKernelHandleTable;
  v25 = a1[3];
  v12 = ObpIncrementHandleCountEx(2, &v25, a2, a1[2], v6, a1[5], 0);
  if ( v12 < 0 )
    goto LABEL_23;
  v13 = a1[2];
  v14 = v13 - 24;
  v15 = ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(v13 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v13 - 12)];
  v29[1] = (int)v29;
  v28 = v15;
  v29[0] = (int)v29;
  if ( (*(_BYTE *)(v15 + 42) & 0x40) != 0 && *(_DWORD *)(v15 + 136) != v15 + 136 )
  {
    v26 = v25;
    v23 = ObpPreInterceptHandleDuplicate(v13, v11);
    v12 = v23;
    if ( v23 >= 0 )
    {
      if ( !v11 )
        v25 = v26;
      goto LABEL_5;
    }
    ObpDecrementHandleCount(a2, v14);
LABEL_23:
    v20 = (unsigned int *)(a2 + 172);
    __pld((void *)(a2 + 172));
    v21 = *(_DWORD *)(a2 + 172) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v22 = __ldrex(v20);
    while ( v22 == v21 && __strex(v21 - 2, v20) );
    if ( v22 != v21 )
      ExfReleaseRundownProtection((unsigned __int8 *)v20);
    return v12;
  }
LABEL_5:
  ObfReferenceObjectWithTag(a1[2]);
  v24 = a1[4];
  v16 = ExCreateHandleEx(v9);
  if ( v16 )
  {
    if ( (a1[5] & 4) != 0 && SeAuditingWithTokenForSubcategory(123) )
      SeAuditHandleDuplication(a1[1], v16, *a1, a2, v24);
  }
  else
  {
    ObfDereferenceObjectWithTag(a1[2]);
    ObpDecrementHandleCount(a2, v14);
    v12 = -1073741670;
  }
  if ( v11 )
    v16 |= 0x80000000;
  v17 = (unsigned int *)(a2 + 172);
  __pld((void *)(a2 + 172));
  v18 = *(_DWORD *)(a2 + 172) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v19 = __ldrex(v17);
  while ( v19 == v18 && __strex(v18 - 2, v17) );
  if ( v19 != v18 )
    ExfReleaseRundownProtection((unsigned __int8 *)v17);
  if ( (int *)v29[0] != v29 )
    ObpPostInterceptHandleDuplicate(a1[2], v11, v12, v25, v29);
  if ( v12 >= 0 )
  {
    *v27 = v16;
    *a5 = v25;
  }
  if ( (dword_682610 & 0x40) != 0 && v12 >= 0 )
    EtwTraceDuplicateHandle(a1[1], v16, a1[2], *(_DWORD *)(*a1 + 176), *(_DWORD *)(a2 + 176), v28);
  return v12;
}
