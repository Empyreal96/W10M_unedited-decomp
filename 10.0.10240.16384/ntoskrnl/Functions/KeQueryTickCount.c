// KeQueryTickCount 
 
int *__fastcall KeQueryTickCount(int *result)
{
  int v1; // r3
  int v2; // r3

  v1 = dword_690384;
  __dmb(0xBu);
  result[1] = v1;
  v2 = KeTickCount;
  __dmb(0xBu);
  *result = v2;
  if ( result[1] != dword_690388 )
    result = (int *)sub_50DCC4();
  return result;
}
