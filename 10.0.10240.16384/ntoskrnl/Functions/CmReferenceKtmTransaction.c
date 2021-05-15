// CmReferenceKtmTransaction 
 
int __fastcall CmReferenceKtmTransaction(int a1)
{
  int v2; // r4

  v2 = 0;
  ObfReferenceObject(a1);
  if ( !TmIsTransactionActive() )
  {
    ObfDereferenceObject(a1);
    v2 = -1072103421;
  }
  return v2;
}
