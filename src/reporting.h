/*
 * reporting.h
 *
 *  Created on: Jul 28, 2019
 *      Author: denis
 */

#ifndef REPORTING_H_
#define REPORTING_H_

#include "convert.h"

#define VREF (FRAC_BASE*3 + (FRAC_BASE*3.0)/10.0)

void reporting_service(char msg);

#endif /* REPORTING_H_ */
