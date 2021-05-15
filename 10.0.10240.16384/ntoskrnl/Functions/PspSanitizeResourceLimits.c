// PspSanitizeResourceLimits 
 
int __fastcall PspSanitizeResourceLimits(_DWORD *a1, int a2)
{
  int v2; // r5
  char *v3; // r6
  _DWORD *v4; // r2
  char v5; // r3
  char v6; // t1
  unsigned int v8; // r3
  unsigned int v9; // r3

  v2 = 0;
  v3 = PspResourceFlags;
  v4 = a1;
  do
  {
    v6 = *v3;
    v3 += 8;
    v5 = v6;
    if ( (v6 & 2) != 0 )
      return sub_80E9A0(a1, a2, v4);
    if ( (v5 & 1) != 0 && !*v4 )
      *v4 = -1;
    ++v2;
    ++v4;
  }
  while ( v2 < 4 );
  v8 = *a1;
  if ( *a1 == -1 )
    goto LABEL_9;
  if ( v8 < 0xFFF )
  {
    *a1 = v8 << 20;
    goto LABEL_9;
  }
  if ( !a2 )
LABEL_19:
    JUMPOUT(0x80E9C2);
  *a1 = -1;
LABEL_9:
  v9 = a1[1];
  if ( v9 != -1 )
  {
    if ( v9 < 0xFFF )
    {
      a1[1] = v9 << 20;
      return 0;
    }
    if ( a2 )
    {
      a1[1] = -1;
      return 0;
    }
    goto LABEL_19;
  }
  return 0;
}
