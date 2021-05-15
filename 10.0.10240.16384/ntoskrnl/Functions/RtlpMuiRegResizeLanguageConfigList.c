// RtlpMuiRegResizeLanguageConfigList 
 
int __fastcall RtlpMuiRegResizeLanguageConfigList(int a1, int a2)
{
  signed int v2; // r4
  int result; // r0
  int v5; // r3
  int v6; // [sp+0h] [bp-20h]
  int v7; // [sp+4h] [bp-1Ch]
  int v8[4]; // [sp+10h] [bp-10h] BYREF

  v2 = a2;
  if ( a2 < 1 )
    v2 = 4;
  result = 0;
  if ( a1 && v2 >= *(unsigned __int16 *)(a1 + 4) )
  {
    result = sub_5CA63C((unsigned int *)a1, 0xCu, v2, 12, v6, v7, v8);
    if ( result )
    {
      v5 = v8[0];
      *(_WORD *)(result + 6) = v2;
      *(_DWORD *)result = v5;
      *(_DWORD *)(result + 8) = result + 12;
    }
  }
  return result;
}
