// RtlpGenerateInheritAcl 
 
int __fastcall RtlpGenerateInheritAcl(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, char a12, _DWORD *a13, int a14, _BYTE *a15)
{
  int v16; // r4
  int v17; // r10
  unsigned int v18; // r6
  int v19; // r8
  unsigned int v20; // r9
  int v21; // r5
  int v22; // r0
  int result; // r0
  char v24[4]; // [sp+28h] [bp-38h] BYREF
  int v25; // [sp+2Ch] [bp-34h]
  int v26; // [sp+30h] [bp-30h]
  int v27; // [sp+34h] [bp-2Ch]
  unsigned int v28; // [sp+38h] [bp-28h] BYREF
  unsigned int v29[9]; // [sp+3Ch] [bp-24h] BYREF

  v16 = *(unsigned __int16 *)(a1 + 4);
  v25 = a4;
  v26 = a3;
  v17 = 0;
  v18 = 0;
  v27 = a2;
  v19 = 0;
  v20 = 0;
  *a15 = 0;
  v21 = a1 + 8;
  if ( v16 )
  {
    v22 = a14;
    while ( 1 )
    {
      if ( *(_BYTE *)v21 == 17 )
      {
        if ( a11 == 3 )
        {
          if ( RtlFindAceByType(v22, 17, 0) )
          {
LABEL_14:
            if ( !v17 )
              break;
LABEL_22:
            *a13 = v20 + v19;
            return -1073741789;
          }
          v22 = a14;
LABEL_5:
          result = RtlpGenerateInheritedAce(v21, v27, v26, v25, a5, a6, a7, a8, a9, a10, &v28, v22, v29, v24);
          if ( result == -1073741789 )
          {
            v17 = 1;
          }
          else if ( result < 0 )
          {
            return result;
          }
          if ( v24[0] )
            return sub_7FB7B8();
          v19 += v28;
          if ( v28 > v20 || (v20 -= v28, v20 <= v29[0]) )
            v20 = v29[0];
          v22 = a14;
          goto LABEL_13;
        }
      }
      else if ( a11 != 3 )
      {
        goto LABEL_5;
      }
LABEL_13:
      ++v18;
      v21 += *(unsigned __int16 *)(v21 + 2);
      if ( v18 >= *(unsigned __int16 *)(a1 + 4) )
        goto LABEL_14;
    }
  }
  if ( a12 )
    goto LABEL_22;
  result = 0;
  *a13 = v19;
  return result;
}
