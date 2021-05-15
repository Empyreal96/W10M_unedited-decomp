// DrvDbDeleteDriverDatabase 
 
int __fastcall DrvDbDeleteDriverDatabase(int a1, unsigned __int16 *a2)
{
  int result; // r0
  unsigned __int16 *v4; // [sp+0h] [bp-8h] BYREF

  v4 = 0;
  result = DrvDbFindDatabaseNode(a1, a2, &v4, 0);
  if ( result >= 0 )
  {
    if ( (*((_DWORD *)v4 + 7) & 0x10) != 0 )
      result = DrvDbDestroyDatabaseNode(a1, v4);
    else
      result = -1073741790;
  }
  return result;
}
