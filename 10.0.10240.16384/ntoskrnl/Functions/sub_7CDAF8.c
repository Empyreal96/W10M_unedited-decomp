// sub_7CDAF8 
 
void __fastcall sub_7CDAF8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, unsigned __int16 a9, int a10, int a11, int a12, int a13, int a14)
{
  unsigned __int16 *v14; // r4

  HIWORD(a13) = a9 + *v14;
  if ( ExAllocatePoolWithTag(1, HIWORD(a13), 1413770573) )
  {
    LOWORD(a13) = 0;
    RtlAppendUnicodeStringToString((unsigned __int16 *)&a13, v14);
    RtlAppendUnicodeStringToString((unsigned __int16 *)&a13, &a9);
    JUMPOUT(0x772254);
  }
  JUMPOUT(0x7723D8);
}
