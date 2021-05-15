// sub_7D0DE8 
 
void sub_7D0DE8()
{
  int v0; // r6
  int *v1; // r7
  int v2; // r8
  int v3; // r9
  int *v4; // r5
  int v5; // r4
  int v6; // t1

  v4 = v1;
  while ( 1 )
  {
    v6 = *v4++;
    v5 = v6;
    if ( *(_BYTE *)(v6 + 37) && v2 )
      WdipSemEnableDisableTrace((unsigned __int16)v2, v5, 0);
    if ( *(_BYTE *)(v5 + 69) && v3 )
      WdipSemEnableDisableTrace((unsigned __int16)v3, v5, 0);
    if ( ++v0 >= (unsigned int)v1[1024] )
      JUMPOUT(0x78B186);
  }
}
