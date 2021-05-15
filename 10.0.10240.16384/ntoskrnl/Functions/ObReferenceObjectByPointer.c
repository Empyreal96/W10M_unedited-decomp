// ObReferenceObjectByPointer 
 
int __fastcall ObReferenceObjectByPointer(int a1, int a2, int a3, char a4)
{
  unsigned int *v4; // r5
  unsigned int v6; // r2
  signed int v7; // r2

  v4 = (unsigned int *)(a1 - 24);
  if ( a3 )
  {
    if ( ObTypeIndexTable[BYTE1(v4) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(a1 - 12)] != a3 )
      return -1073741788;
  }
  else if ( a4 )
  {
    return -1073741788;
  }
  if ( ObpTraceFlags )
    return sub_51B9EC();
  do
  {
    v6 = __ldrex(v4);
    v7 = v6 + 1;
  }
  while ( __strex(v7, v4) );
  __dmb(0xBu);
  if ( v7 <= 1 )
    KeBugCheckEx(24, 0, a1);
  return 0;
}
