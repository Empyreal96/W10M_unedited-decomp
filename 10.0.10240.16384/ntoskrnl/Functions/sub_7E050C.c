// sub_7E050C 
 
void __fastcall sub_7E050C(int a1, int a2, int a3, int a4, unsigned int a5, int a6)
{
  int v6; // r5

  if ( v6 && v6 != 4 )
  {
    a5 = -10000;
    a6 = -1;
    KeDelayExecutionThread(0, 0, &a5);
    JUMPOUT(0x7765BC);
  }
  JUMPOUT(0x7765CC);
}
