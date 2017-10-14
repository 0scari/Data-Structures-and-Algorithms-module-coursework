//
// Created by Oskars Pozdnakovs on 12/10/2017.
//

#ifndef WEEK_1_ADVANCED2_H
#define WEEK_1_ADVANCED2_H

string advanced2 (Lorry &lorry, Warehouse warehouse) {

    while (warehouse.hasStock() && !lorry.isFull()) {

        // getMostExpensiveMaterial returns a map with 1 element
        // 'for' is used in order to refer to that element by key(first)/value(second)
        for (auto payload : warehouse.getMostExpensiveMaterial())
            lorry.addPayload(payload.first, payload.second);

    }

    return lorry.prepareInvoice();

}

#endif //WEEK_1_ADVANCED2_H
