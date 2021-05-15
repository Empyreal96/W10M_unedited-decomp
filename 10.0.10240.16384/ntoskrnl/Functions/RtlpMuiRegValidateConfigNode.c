// RtlpMuiRegValidateConfigNode 
 
int __fastcall RtlpMuiRegValidateConfigNode(int a1, __int16 *a2)
{
  unsigned int v3; // r4
  int v4; // r2
  int v6; // r4
  _WORD *v7; // r7
  int v8; // r5
  int v9; // r0
  int v10; // r8
  int v11; // r1
  int v12; // r2
  int v13; // r9
  __int16 v14; // r1
  __int16 v16; // [sp+10h] [bp-30h] BYREF
  __int16 v17; // [sp+12h] [bp-2Eh] BYREF
  _WORD *v18; // [sp+14h] [bp-2Ch] BYREF
  int v19; // [sp+18h] [bp-28h]
  int v20; // [sp+1Ch] [bp-24h]

  v3 = (unsigned __int16)a2[1];
  v4 = *a2;
  v16 = -1;
  v6 = RtlpMuiRegGetInstalledLanguageIndex(a1, v3 >> 14, v4, &v17);
  if ( v6 >= 0 )
  {
    v7 = (_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 20) + 12) + 28 * v17);
    if ( (*v7 & 0x1000) != 0 )
    {
LABEL_3:
      v6 = -1073741772;
    }
    else
    {
      v8 = 0;
      while ( 1 )
      {
        v9 = ((unsigned __int16)a2[1] >> (2 * v8)) & 3;
        v20 = v9;
        if ( !v9 )
          break;
        if ( !v7 )
          goto LABEL_3;
        v10 = 2 * v8;
        v11 = a2[v8 + 3];
        LOBYTE(v12) = 0;
        v13 = 0;
        v19 = v11;
        while ( 1 )
        {
          v18 = 0;
          if ( RtlpMuiRegConfigMatchesInstalled(
                 a1,
                 v9,
                 v11,
                 ((unsigned __int16)v7[4] >> (2 * v12)) & 3,
                 (__int16)v7[v13 + 6],
                 &v18,
                 &v16)
            && (!v18 || (*v18 & 0x1000) == 0)
            && ((*v7 & 4) == 0 || v18) )
          {
            break;
          }
          v12 = (__int16)(v13 + 1);
          v13 = v12;
          if ( v12 >= 4 )
            goto LABEL_3;
          v11 = v19;
          v9 = v20;
        }
        v14 = v16;
        v7 = v18;
        if ( v16 != -1 )
        {
          a2[1] = (2 << v10) | a2[1] & ~(3 << v10);
          a2[v10 / 2u + 3] = v14;
        }
        v8 = (__int16)(v8 + 1);
        if ( v8 >= 3 )
          return v6;
      }
      if ( !v8 )
        v6 = -1073741823;
    }
  }
  return v6;
}
