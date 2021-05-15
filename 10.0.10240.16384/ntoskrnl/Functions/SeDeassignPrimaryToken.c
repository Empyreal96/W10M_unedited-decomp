// SeDeassignPrimaryToken 
 
int __fastcall SeDeassignPrimaryToken(int a1)
{
  int v1; // r0

  v1 = ObFastReplaceObject((unsigned int *)(a1 + 244), 0);
  *(_BYTE *)(v1 + 180) = 0;
  return ObfDereferenceObject(v1);
}
