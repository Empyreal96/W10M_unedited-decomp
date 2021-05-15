// ExAdjustLookasideDepth 
 
void ExAdjustLookasideDepth()
{
  int v0; // r3
  int *v1; // r1
  int *v2; // r0

  v0 = ExpScanCount;
  if ( !ExpScanCount )
  {
    v1 = &ExNPagedLookasideLock;
    v2 = &ExNPagedLookasideListHead;
LABEL_6:
    ExpScanGeneralLookasideList(v2, v1);
    goto LABEL_7;
  }
  if ( ExpScanCount == 1 )
  {
    v1 = &ExPagedLookasideLock;
    v2 = &ExPagedLookasideListHead;
    goto LABEL_6;
  }
  if ( ExpScanCount != 2 )
    goto LABEL_8;
  ExpScanSystemLookasideList();
LABEL_7:
  v0 = ExpScanCount;
LABEL_8:
  ExpScanCount = v0 + 1;
  if ( v0 == 2 )
    ExpScanCount = 0;
}
