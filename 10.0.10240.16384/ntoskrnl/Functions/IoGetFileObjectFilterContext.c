// IoGetFileObjectFilterContext 
 
int __fastcall IoGetFileObjectFilterContext(int a1, int *a2, int a3)
{
  int *v4; // r4
  int v6; // r3
  int result; // r0

  v4 = *(int **)(a1 + 124);
  if ( v4 )
  {
LABEL_2:
    if ( v4 != IopRevocationExtension )
    {
      v6 = v4[4];
LABEL_4:
      result = 0;
LABEL_5:
      *a2 = v6;
      return result;
    }
LABEL_10:
    v6 = 0;
    goto LABEL_4;
  }
  if ( a3 )
  {
    result = IopAllocateFileObjectExtension(a1, 0);
    if ( result < 0 )
    {
      v6 = 0;
      goto LABEL_5;
    }
    v4 = *(int **)(a1 + 124);
    if ( !v4 )
      goto LABEL_10;
    goto LABEL_2;
  }
  return sub_51E8B8();
}
