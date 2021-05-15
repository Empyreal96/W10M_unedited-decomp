// FindBitmapResource 
 
int __fastcall FindBitmapResource(int a1, int a2)
{
  int result; // r0
  int v4; // [sp+0h] [bp-20h] BYREF
  int *v5; // [sp+4h] [bp-1Ch] BYREF
  _DWORD v6[6]; // [sp+8h] [bp-18h] BYREF

  v6[0] = 2;
  v6[1] = a1;
  v6[2] = 0;
  if ( LdrFindResource_U(0x400000, (int)v6, 3u, &v5) < 0
    || LdrAccessResource(0x400000, (unsigned int)v5, (int)&v4, a2) < 0 )
  {
    result = 0;
  }
  else
  {
    result = v4;
  }
  return result;
}
