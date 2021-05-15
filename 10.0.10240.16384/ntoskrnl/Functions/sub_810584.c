// sub_810584 
 
int __fastcall sub_810584(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int *a8)
{
  unsigned int v8; // r9
  _BYTE *v9; // r0
  _DWORD *v10; // r7
  int v11; // r2
  int v12; // r3
  int v13; // r6
  unsigned int v14; // r2
  int v15; // r8
  unsigned int v16; // r4
  int v18; // r6
  int v19; // r8
  int v20; // r5
  int v21; // r2
  char v22; // r3
  int v23; // r0
  unsigned __int8 *v24; // r3
  unsigned int v25; // r2
  int v26; // r4
  int v27; // r2
  char v28; // r3
  int v29; // r0
  unsigned __int8 *v30; // r3
  unsigned int v31; // r2
  int v32; // r2
  int v33; // r3
  int (__fastcall *v34)(int); // [sp-4h] [bp-4h]

  v19 = a6;
  a7 = a6;
  v20 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xEB8);
  if ( *(&KeNodeBlock + *(unsigned __int16 *)(v20 + 266)) == (char *)&KiNodeInit
                                                           + 384 * *(unsigned __int16 *)(v20 + 266) )
    v20 = 0;
  v8 = *(unsigned __int16 *)(v20 + 266);
  v9 = (_BYTE *)ExAllocatePoolWithTag(512, 440, 1817671749);
  v10 = v9;
  if ( !v9 )
  {
    v21 = a6;
    v22 = a6 & 7;
    __dmb(0xBu);
    v23 = 1 << v22;
    v24 = (unsigned __int8 *)(v18 + (v21 >> 3));
    do
      v25 = __ldrex(v24);
    while ( __strex(v25 | v23, v24) );
    v26 = -1073741801;
    goto LABEL_8;
  }
  memset(v9, 0, 440);
  v10[107] = v10[107] & 0x80000000 | 1;
  v10[108] = 16;
  v10[109] = v19;
  v10[103] = v20;
  KeQueryNodeActiveAffinity(v8, 0, &a5);
  KeInitializePriQueue((int)v10, (unsigned __int16)a5);
  v26 = ExpCreateWorkerThread(v20, (int)v10, v11, v12);
  if ( v26 < 0 )
  {
    ExFreePoolWithTag((unsigned int)v10);
    v27 = a6;
    v28 = a6 & 7;
    __dmb(0xBu);
    v29 = 1 << v28;
    v30 = (unsigned __int8 *)(v18 + (v27 >> 3));
    do
      v31 = __ldrex(v30);
    while ( __strex(v31 | v29, v30) );
LABEL_8:
    __dmb(0xBu);
    return v34(v26);
  }
  __dmb(0xBu);
  v13 = v19 + 96;
  *(_DWORD *)(v20 + 4 * (v19 + 96)) = v10;
  a5 = (2 * (v8 & 0x7F)) | 1;
  v14 = 0;
  if ( KeNumberNodes )
  {
    v15 = a5;
    v16 = 0;
    do
    {
      if ( v16 != v8 )
      {
        v32 = (int)*(&KeNodeBlock + v14);
        if ( (_UNKNOWN *)v32 != (_UNKNOWN *)((char *)&KiNodeInit + 384 * v16) )
        {
          if ( v32 )
          {
            v33 = *(_DWORD *)(v32 + 1016);
            __dmb(0xBu);
            if ( (v33 & 1) != 0 )
            {
              __dmb(0xBu);
              *(_DWORD *)(v32 + 4 * v13) = v15;
              KeSetEvent(v32 + 856, 0, 0);
            }
          }
        }
      }
      v14 = (unsigned __int16)(v16 + 1);
      v16 = v14;
    }
    while ( v14 < (unsigned __int16)KeNumberNodes );
    v19 = a7;
  }
  v26 = 0;
  *a8 = v19;
  return v34(v26);
}
