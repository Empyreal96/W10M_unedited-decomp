// CmpGetValueDataFromCache 
 
int __fastcall CmpGetValueDataFromCache(int a1, int a2, int a3, _BYTE *a4, int a5)
{
  int result; // r0
  int v6; // [sp+10h] [bp-10h] BYREF
  unsigned int v7[3]; // [sp+14h] [bp-Ch] BYREF

  if ( CmpGetValueData(*(_DWORD *)(a1 + 20), a2, a3, v7, &v6, a4, a5) )
    result = v6;
  else
    result = 0;
  return result;
}
