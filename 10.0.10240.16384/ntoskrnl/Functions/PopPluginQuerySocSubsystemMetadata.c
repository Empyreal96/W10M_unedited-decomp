// PopPluginQuerySocSubsystemMetadata 
 
int __fastcall PopPluginQuerySocSubsystemMetadata(int a1, int a2, int a3)
{
  unsigned int v4; // r7
  int v6; // r9
  _BYTE *v7; // r0
  unsigned int v8; // r8
  _BYTE *v9; // r0
  unsigned int v10; // r4
  int *v11; // r2
  _DWORD *v12; // r0
  int v13; // r5
  unsigned int v14; // lr
  _DWORD *v15; // r2
  _DWORD *v16; // r1
  int v17; // r2
  unsigned __int16 *v18; // r5
  unsigned int v19; // r5
  int v20; // r10
  unsigned int v21; // r8
  int v22; // r3
  unsigned __int16 *v23; // r9
  int v24; // r3
  _BYTE *v26; // [sp+0h] [bp-38h]
  int v27; // [sp+4h] [bp-34h]
  _BYTE *v28; // [sp+8h] [bp-30h] BYREF
  _BYTE *v29; // [sp+Ch] [bp-2Ch]
  int v30; // [sp+10h] [bp-28h]

  v4 = *(_DWORD *)(a3 + 16);
  v29 = (_BYTE *)a2;
  v6 = 0;
  v7 = (_BYTE *)ExAllocatePoolWithTag(1, 8 * v4, 1297630800);
  v8 = (unsigned int)v7;
  v26 = v7;
  if ( v7 )
  {
    memset(v7, 0, 8 * v4);
    v9 = (_BYTE *)ExAllocatePoolWithTag(1, 8 * v4, 1297630800);
    v10 = (unsigned int)v9;
    if ( v9 )
    {
      memset(v9, 0, 8 * v4);
      v11 = *(int **)(a3 + 8);
      v30 = *v11;
      v27 = v11[1];
      if ( v4 )
      {
        v12 = (_DWORD *)v10;
        v13 = a3;
        v14 = v4;
        do
        {
          v15 = *(_DWORD **)(v13 + 20);
          v16 = (_DWORD *)((char *)v12 + v8 - v10);
          *v16 = *v15;
          v16[1] = v15[1];
          v17 = *(_DWORD *)(v13 + 20);
          v13 += 4;
          *v12 = *(_DWORD *)(v17 + 8);
          v12[1] = *(_DWORD *)(v17 + 12);
          v12 += 2;
          --v14;
        }
        while ( v14 );
      }
      v6 = (*(int (__fastcall **)(int, int))(a1 + 64))(40, a3);
      if ( !v6 )
        PopFxBugCheck(1541, 40, PopFxProcessorPlugin, 0);
      v18 = *(unsigned __int16 **)(a3 + 8);
      RtlHashUnicodeString(v18, 0, 0, (unsigned int *)&v28);
      if ( __PAIR64__(v18[1], *v18) != __PAIR64__(HIWORD(v30), (unsigned __int16)v30)
        || *((_DWORD *)v18 + 1) != v27
        || v28 != v29 )
      {
        PopFxBugCheck(1797, a1, 40, 1397645677);
      }
      v19 = 0;
      if ( v4 )
      {
        v20 = a3;
        v21 = v10;
        v22 = (int)&v26[-v10];
        v29 = &v26[-v10];
        do
        {
          v23 = *(unsigned __int16 **)(v20 + 20);
          if ( !PopFxValidateReturnedUnicodeString(
                  v23,
                  *(_WORD **)(v22 + v21 + 4),
                  *(unsigned __int16 *)(v22 + v21 + 2),
                  v22 + v21) )
            PopFxBugCheck(1798, 40, 1264941344, *(_DWORD *)(a3 + 4 * v19 + 20) + 4);
          v6 = PopFxValidateReturnedUnicodeString(v23 + 4, *(_WORD **)(v21 + 4), *(unsigned __int16 *)(v21 + 2), v24);
          if ( !v6 )
            PopFxBugCheck(1798, 40, 1449225333, *(_DWORD *)(a3 + 4 * v19 + 20) + 12);
          ++v19;
          v22 = (int)v29;
          v21 += 8;
          v20 += 4;
        }
        while ( v19 < v4 );
        v8 = (unsigned int)v26;
      }
    }
    ExFreePoolWithTag(v8);
    if ( v10 )
      ExFreePoolWithTag(v10);
  }
  return v6;
}
