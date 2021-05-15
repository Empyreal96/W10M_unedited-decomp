// ExQueryClipSp 
 
int __fastcall ExQueryClipSp(int a1, int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  int v7; // r4
  int v9; // [sp+10h] [bp-30h] BYREF
  int v10; // [sp+14h] [bp-2Ch]
  int v11; // [sp+18h] [bp-28h]
  int v12; // [sp+1Ch] [bp-24h]

  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  if ( a1 == 3 )
  {
    if ( off_9204B0 )
      v7 = off_9204B0();
    else
      v7 = -1073741637;
    if ( v7 >= 0 )
    {
      v9 = 1;
      v10 = 0;
      *a6 = 16;
      if ( a4 < 0x10 )
        v7 = -1073741789;
      else
        memmove(a5, (int)&v9, 0x10u);
    }
    return v7;
  }
  if ( a1 )
    return -1073741198;
  return sub_51C84C();
}
