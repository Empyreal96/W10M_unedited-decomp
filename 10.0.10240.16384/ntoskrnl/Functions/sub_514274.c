// sub_514274 
 
void __fastcall sub_514274(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r4
  int v7; // r7
  int v8; // r7

  if ( KeSetIdealProcessorThreadEx(v6 & 0xFFFFFFC0, v7, (unsigned int *)&a5, a4) >= 0 )
    v8 = a5;
  else
    v8 = -1;
  a6 = v8;
  JUMPOUT(0x430C80);
}
