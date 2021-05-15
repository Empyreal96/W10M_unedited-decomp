// sub_565FC4 
 
int __fastcall sub_565FC4(_BYTE *a1, int a2, int a3, _DWORD *a4, _DWORD *a5, _DWORD *a6, __int16 a7)
{
  if ( (a7 & 0x1000) != 0 )
  {
    *a5 = a1;
    *a6 = a2;
    *a4 = 0;
  }
  if ( (a7 & 0x400) != 0 )
  {
    memset(a1, (unsigned __int8)a7, 2 * a2);
    *a5 = a1;
    *a6 = a2;
    *a4 = 0;
  }
  if ( (a7 & 0x800) != 0 )
  {
    *a5 = a1;
    *a6 = a2;
    *a4 = 0;
  }
  return 0;
}
