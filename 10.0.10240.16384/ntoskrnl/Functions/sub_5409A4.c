// sub_5409A4 
 
void sub_5409A4()
{
  int v0; // r4
  unsigned int v1; // r5
  unsigned int *v2; // r6
  unsigned int v3; // r1
  int v4; // r7
  unsigned int v5; // r2
  unsigned int v6; // r3
  int *i; // r1

  v3 = v1;
  v4 = dword_61633C;
  do
  {
    if ( !v3 )
      goto LABEL_11;
    v5 = __clz(__rbit(v3));
    v3 &= ~(1 << v5);
    if ( v5 >= *v2 )
      v6 = 0;
    else
      v6 = v2[v5 + 13];
  }
  while ( (*(_DWORD *)(*(_DWORD *)(v6 + 3200) + 20) & dword_61633C) == *(_DWORD *)(*(_DWORD *)(v6 + 3200) + 20) );
  for ( i = (int *)PpmPerfDomainHead; i != &PpmPerfDomainHead; i = (int *)*i )
  {
    if ( (i[5] & v4) != i[5] )
    {
      v1 |= 1 << *(_DWORD *)(i[2] + 20);
      *(_DWORD *)(v0 + 8) = v1;
    }
  }
LABEL_11:
  JUMPOUT(0x4AD470);
}
