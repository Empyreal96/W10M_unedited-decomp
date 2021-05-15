// sub_812D5C 
 
void sub_812D5C()
{
  unsigned __int16 *v0; // r6
  unsigned __int16 *v1; // r7
  char **v2; // r9
  unsigned int v3; // r4
  unsigned int v4; // r8
  char *v5; // r0
  char *v6; // r4

  v3 = wcslen(v0);
  v4 = v3 + wcslen(v1);
  v5 = (char *)ExAllocatePoolWithTag(1, 2 * (v4 + 1), 1262764866);
  v6 = v5;
  if ( v5 )
  {
    wcscpy_s(v5, v4 + 1, (char *)v0);
    wcscat_s(v6, v4 + 1, (char *)v1);
    *v2 = v6;
  }
  JUMPOUT(0x7A4598);
}
