// EtwpObjectHandleEnumCallback 
 
int __fastcall EtwpObjectHandleEnumCallback(int a1, unsigned int *a2, unsigned int a3, int a4)
{
  int v7; // r10
  unsigned int v8; // r4
  unsigned int v9; // r0
  int v10; // r4
  int v11; // r8
  unsigned __int16 *v12; // lr
  unsigned int v13; // r9
  int v14; // r4
  int v15; // t1
  unsigned int v16; // r1
  int v17; // r2
  int v18; // r0
  unsigned int v19; // r1
  int v20; // r2
  unsigned __int16 *v21; // r4
  int v22; // r6
  int v23; // r7
  unsigned int v24; // r1
  int v25; // r3
  int v26; // r2
  int *v27; // r1
  int i; // [sp+8h] [bp-68h] BYREF
  int v30; // [sp+Ch] [bp-64h] BYREF
  _DWORD v31[2]; // [sp+10h] [bp-60h] BYREF
  unsigned int v32; // [sp+18h] [bp-58h]
  __int16 v33; // [sp+1Ch] [bp-54h]
  int v34[20]; // [sp+20h] [bp-50h] BYREF

  v7 = 4391;
  if ( *(_BYTE *)(a4 + 36) )
    v7 = 4390;
  v8 = *a2;
  v32 = a3;
  v9 = v8 & 0xFFFFFFF8;
  v10 = *(_DWORD *)(a4 + 24);
  v11 = v9 + 24;
  v31[0] = v9 + 24;
  v31[1] = v10;
  if ( *(_BYTE *)(a4 + 40) )
    v32 = a3 | 0x80000000;
  v12 = *(unsigned __int16 **)(a4 + 4);
  v33 = *(unsigned __int8 *)(v9 + 12) ^ BYTE1(v9) ^ (unsigned __int8)ObHeaderCookie;
  if ( !v12 )
  {
LABEL_15:
    ObfReferenceObjectWithTag(v11);
    __dmb(0xBu);
    do
      v19 = __ldrex(a2);
    while ( __strex(v19 + 1, a2) );
    __dmb(0xBu);
    __dmb(0xFu);
    if ( *(_DWORD *)(a1 + 32) )
      ExfUnblockPushLock(a1 + 32, 0);
    v34[0] = (int)v31;
    v34[1] = 0;
    v20 = *(unsigned __int16 *)(a4 + 12);
    v34[2] = 14;
    v21 = *(unsigned __int16 **)(a4 + 8);
    v34[3] = 0;
    v22 = 1;
    for ( i = v20; ; v20 = i )
    {
      v23 = ObQueryNameStringMode(v11, (int)v21, v20, &i, 0);
      if ( v23 != -1073741820 )
        break;
      if ( v21 != *(unsigned __int16 **)(a4 + 8) )
        ExFreePoolWithTag((unsigned int)v21);
      v21 = (unsigned __int16 *)ExAllocatePoolWithTag(1, i, 1953985605);
      if ( !v21 )
        break;
    }
    ObfDereferenceObjectWithTag(v11);
    if ( !v23 )
    {
      v25 = 0x2000;
      if ( *v21 < 0x2000u )
        v25 = *v21;
      v26 = *((_DWORD *)v21 + 1);
      v34[6] = v25;
      v34[4] = v26;
      v34[5] = 0;
      v34[7] = 0;
      v22 = 2;
    }
    v27 = &v34[4 * v22];
    *v27 = (int)&EtwpNull;
    v27[1] = 0;
    v27[2] = 2;
    v27[3] = 0;
    EtwpLogKernelEvent(v34, *(_DWORD *)(a4 + 16), v22 + 1, v7, 4200450);
    if ( v21 && v21 != *(unsigned __int16 **)(a4 + 8) )
      ExFreePoolWithTag((unsigned int)v21);
    return 0;
  }
  v13 = *v12;
  v14 = 0;
  if ( *v12 )
  {
    i = *(_DWORD *)(ObTypeIndexTable[*(unsigned __int8 *)(v9 + 12) ^ BYTE1(v9) ^ (unsigned __int8)ObHeaderCookie] + 132);
LABEL_8:
    v15 = *((_DWORD *)v12 + 1);
    v12 += 2;
    v16 = 0;
    v17 = 0;
    v30 = v15;
    while ( 1 )
    {
      v18 = *((unsigned __int8 *)&v30 + v17);
      if ( v18 == 42 )
        goto LABEL_15;
      if ( v18 != 63 && (v16 != 3 || (*((_BYTE *)&i + v17) & 0x7F) != v18) && *((unsigned __int8 *)&i + v17) != v18 )
      {
        if ( ++v14 < v13 )
          goto LABEL_8;
        break;
      }
      ++v16;
      ++v17;
      if ( v16 >= 4 )
        goto LABEL_15;
    }
  }
  __dmb(0xBu);
  do
    v24 = __ldrex(a2);
  while ( __strex(v24 + 1, a2) );
  __dmb(0xBu);
  __dmb(0xFu);
  if ( *(_DWORD *)(a1 + 32) )
    ExfUnblockPushLock(a1 + 32, 0);
  return 0;
}
