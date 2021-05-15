// PsEnterPriorityRegion 
 
int PsEnterPriorityRegion()
{
  return PsBoostThreadIoEx(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0, 0);
}
