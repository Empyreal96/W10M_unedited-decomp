// IoGetTransactionParameterBlock 
 
int __fastcall IoGetTransactionParameterBlock(int a1)
{
  int *v1; // r2

  v1 = *(int **)(a1 + 124);
  if ( !v1 )
    return 0;
  if ( v1 == IopRevocationExtension )
    return 0;
  return v1[1];
}
