// sub_7EAD30 
 
void sub_7EAD30()
{
  int v0; // r5
  int v1; // r6
  int v2; // r0
  int v3; // r7

  v2 = v0;
  v3 = 5;
  do
  {
    *(_QWORD *)(v2 + 440) += *(_QWORD *)(v1 - v0 + v2 + 440);
    v2 += 8;
    --v3;
  }
  while ( v3 );
  *(_QWORD *)(v0 + 480) += *(_QWORD *)(v1 + 480);
  JUMPOUT(0x70763A);
}
