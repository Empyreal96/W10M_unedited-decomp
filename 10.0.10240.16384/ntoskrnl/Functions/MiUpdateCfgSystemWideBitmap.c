// MiUpdateCfgSystemWideBitmap 
 
int __fastcall MiUpdateCfgSystemWideBitmap(_DWORD *a1, int a2)
{
  int result; // r0

  if ( dword_68124C )
    result = sub_7D50A8(a1, a2, *a1);
  else
    result = 0;
  return result;
}
