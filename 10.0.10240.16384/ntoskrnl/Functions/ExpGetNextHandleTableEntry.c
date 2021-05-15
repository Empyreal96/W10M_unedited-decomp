// ExpGetNextHandleTableEntry 
 
int __fastcall ExpGetNextHandleTableEntry(int a1, int a2, int *a3)
{
  int v4; // r4
  int v5; // r1

  if ( !a2 )
  {
    v4 = 4;
LABEL_6:
    v5 = ExpLookupHandleTableEntry(a1, v4);
    goto LABEL_7;
  }
  v4 = *a3 + 4;
  if ( (*a3 ^ (unsigned int)v4) >= 0x800 )
  {
    v4 = *a3 + 8;
    goto LABEL_6;
  }
  v5 = a2 + 8;
LABEL_7:
  *a3 = v4;
  return v5;
}
