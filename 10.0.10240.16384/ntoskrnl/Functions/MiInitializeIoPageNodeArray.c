// MiInitializeIoPageNodeArray 
 
int __fastcall MiInitializeIoPageNodeArray(int result)
{
  __int16 *v1; // r2
  __int16 *v2; // r1
  __int16 v3; // r3

  v1 = *(__int16 **)(result + 24);
  v2 = v1 + 512;
  while ( v1 < v2 )
  {
    v3 = *v1;
    __dmb(0xBu);
    __dmb(0xBu);
    *v1++ = v3 | 0xC000;
  }
  return result;
}
