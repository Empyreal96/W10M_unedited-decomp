// sub_8085FC 
 
void __fastcall sub_8085FC(_DWORD *a1)
{
  int v1; // r4
  int v2; // r5
  unsigned int *v3; // r5
  unsigned int v4; // r2

  *a1 = 0;
  a1[2] = a1 + 2;
  a1[3] = a1 + 2;
  a1[1] = 0;
  __dmb(0xBu);
  v3 = (unsigned int *)(v2 + 348);
  do
    v4 = __ldrex(v3);
  while ( v4 == v1 && __strex((unsigned int)a1, v3) );
  __dmb(0xBu);
  if ( v4 != v1 )
    ExFreePoolWithTag((unsigned int)a1);
  JUMPOUT(0x75B28A);
}
