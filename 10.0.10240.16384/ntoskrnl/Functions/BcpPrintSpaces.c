// BcpPrintSpaces 
 
int __fastcall BcpPrintSpaces(int *a1, unsigned int a2, unsigned int a3, int a4, int a5, int *a6)
{
  unsigned int v7; // r5
  int v9; // r4
  int result; // r0
  int v12; // [sp+10h] [bp-30h]
  int v13; // [sp+18h] [bp-28h] BYREF
  int v14[9]; // [sp+1Ch] [bp-24h] BYREF

  v7 = a2;
  v9 = 0;
  result = 0;
  v13 = 0;
  if ( a2 >= a3 )
  {
LABEL_5:
    *a6 = v9;
  }
  else
  {
    while ( 1 )
    {
      result = BgpDisplayCharacterEx(32, a1, v7, a4, a5, a5, (int)v14, (int)&v13, v12, (int)BcpWorkspace);
      if ( result < 0 )
        break;
      v7 += v14[0];
      if ( v7 >= a3 )
      {
        v9 = v13;
        goto LABEL_5;
      }
    }
  }
  return result;
}
