// IoInitializeWorkItem 
 
__int16 *__fastcall IoInitializeWorkItem(__int16 *result, _DWORD *a2)
{
  int v2; // r3

  v2 = *result;
  if ( v2 != 3 && v2 != 4 )
    sub_526328();
  a2[8] = 1;
  a2[5] = result;
  a2[7] = 0;
  a2[2] = IopProcessWorkItem;
  a2[3] = a2;
  *a2 = 0;
  return result;
}
