// IopLiveDumpMirrorPhysicalMemoryCallback 
 
int __fastcall IopLiveDumpMirrorPhysicalMemoryCallback(__int64 a1, __int64 a2)
{
  unsigned int v2; // r5
  _DWORD *v3; // r8
  unsigned int v4; // r4
  int v5; // r3
  unsigned int v6; // r2
  unsigned int v7; // r3
  int v8; // r0
  int v9; // r2
  int v10; // r10
  unsigned int v11; // r6
  unsigned int v12; // r7
  unsigned int v13; // r9
  int v14; // r2
  _BYTE *v15; // r0
  unsigned int v17; // [sp+0h] [bp-50h]
  int v18; // [sp+8h] [bp-48h] BYREF
  int v19; // [sp+Ch] [bp-44h]
  int v20; // [sp+10h] [bp-40h]
  unsigned int v21; // [sp+18h] [bp-38h] BYREF
  int v22; // [sp+1Ch] [bp-34h]
  __int64 v23; // [sp+20h] [bp-30h] BYREF
  int v24; // [sp+28h] [bp-28h]
  unsigned int v25; // [sp+2Ch] [bp-24h]
  __int64 varg_r0; // [sp+58h] [bp+8h]
  __int64 varg_r2; // [sp+60h] [bp+10h]

  varg_r0 = a1;
  v2 = a1 >> 12;
  v3 = (_DWORD *)IopLiveDumpContext;
  varg_r2 = a2;
  v19 = v2;
  v4 = (a2 >> 12) + ((a2 & 0xFFF) != 0);
  v5 = *(_DWORD *)(IopLiveDumpContext + 144);
  v22 = 0;
  v17 = v4;
  if ( (v5 & 1) != 0 )
    ReadTimeStampCounter();
  v6 = v4 + v2 - 1;
  v7 = v3[59];
  if ( v2 < v7 )
  {
    if ( v6 >= v7 )
    {
      v6 = v7 - 1;
      v4 = v7 - v2;
      v17 = v7 - v2;
    }
    if ( v4 )
    {
      v21 = v6 + 1;
      v22 = v3[60];
      while ( 1 )
      {
        v8 = RtlFindNextForwardRunClear((int)&v21, v2, (int)&v18);
        v9 = v18;
        v10 = v8;
        v20 = v8;
        v11 = v4;
        if ( v8 )
          v11 = v18 - v2;
        if ( v11 )
          break;
LABEL_28:
        if ( v4 <= v11 + v10 )
        {
          v4 = 0;
        }
        else
        {
          v2 = v9 + v10;
          v19 = v9 + v10;
          v4 = v4 - v11 - v10;
        }
        v17 = v4;
        if ( !v4 )
          return 0;
      }
      v12 = v2;
      v13 = v11;
      while ( 1 )
      {
        v23 = 0i64;
        v24 = 0;
        v25 = 0;
        if ( !MmTryIdentifyPage(v12, (int *)&v23) )
          goto LABEL_26;
        v14 = (v23 >> 4) & 7;
        if ( v14 == 5 || !v14 || v14 == 1 || v14 == 2 || v14 == 3 || v14 == 4 )
          goto LABEL_26;
        if ( v25 < MmSystemRangeStart )
        {
          if ( (v3[5] & 4) == 0 || !v25 || v25 > MmHighestUserAddress )
            goto LABEL_26;
          v15 = v3 + 65;
        }
        else
        {
          v15 = v3 + 62;
        }
        RtlSetBits(v15, v12, 1u);
LABEL_26:
        ++v12;
        if ( !--v13 )
        {
          v4 = v17;
          v2 = v19;
          v10 = v20;
          v9 = v18;
          goto LABEL_28;
        }
      }
    }
  }
  return 0;
}
